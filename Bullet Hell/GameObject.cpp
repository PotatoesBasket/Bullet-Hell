#include "GameObject.h"

GameObject::~GameObject()
{
	if (m_parent != nullptr)
		m_parent->removeChild(this);

	for (auto child : m_children)
		child->m_parent = nullptr;
}

//////////////////////////////
//   Updating and Drawing   //
//////////////////////////////

/*Calls update on the object itself, then its components, then its children.*/
void GameObject::update(float deltaTime)
{
	onUpdate(deltaTime);

	for (auto component : m_components)
		component->update(this, deltaTime);

	for (auto child : m_children)
		child->update(deltaTime);
}

/*Updates the object's transform taking the parent's transform into account,
then does the same for its children.
- Needs to be called within all Transform member functions.*/
void GameObject::updateTransform()
{
	if (m_parent != nullptr)
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	else
		m_globalTransform = m_localTransform;

	for (auto child : m_children)
		child->updateTransform();
}

/*Calls draw on the object itself, then its components, then its children.*/
void GameObject::draw(aie::Renderer2D* renderer)
{
	onDraw(renderer);

	for (auto component : m_components)
		component->draw(this, renderer);

	for (auto child : m_children)
		child->draw(renderer);
}

///////////////////
//   Transform   //
///////////////////

void GameObject::setPosition(float x, float y)
{
	m_localTransform.translation = { x, y, 1 };
	updateTransform();
}

void GameObject::setPosition(const Vector2& v)
{
	m_localTransform.translation = { v.x, v.y, 1 };
	updateTransform();
}

void GameObject::setRotation(float radians)
{
	m_localTransform.setRotateZ(radians);
	updateTransform();
}

void GameObject::setScale(float wMultiplier, float hMultiplier)
{
	m_localTransform.setScaled(wMultiplier, hMultiplier, 1);
	updateTransform();
}

void GameObject::setScale(float multiplier)
{
	m_localTransform.setScaled(multiplier, multiplier, 1);
	updateTransform();
}

void GameObject::move(float x, float y)
{
	m_localTransform.translate(x, y);
	updateTransform();
}
void GameObject::move(const Vector2& v)
{
	m_localTransform.translate(v);
	updateTransform();
}

void GameObject::rotate(float radians)
{
	m_localTransform.rotateZ(radians);
	updateTransform();
}

void GameObject::scale(float wMultiplier, float hMultiplier)
{
	m_localTransform.scale(wMultiplier, hMultiplier, 1);
	updateTransform();
}

void GameObject::scale(float multiplier)
{
	m_localTransform.scale(Vector3(multiplier, multiplier, 1));
	updateTransform();
}

///////////////////
//   Hierarchy   //
///////////////////

void GameObject::addChild(GameObject* child)
{
	if (!child->m_parent) //make sure object isn't already parented to something
	{
		child->m_parent = this; //assign parent to child
		m_children.push_back(child); //add child to parent's list of children
	}
}

void GameObject::removeChild(GameObject* child)
{
	auto it = std::find(m_children.begin(), m_children.end(), child); //find child in list

	if (it != m_children.end())
	{
		m_children.erase(it); //remove child from list
		child->m_parent = nullptr; //remove parent from child
	}
}

/////////////////////
//   Components   ///
/////////////////////

void GameObject::addComponent(const std::shared_ptr<Component>& component)
{
	m_components.push_back(component);
}

void GameObject::removeComponent(const std::shared_ptr<Component>& component)
{
	auto it = std::find(m_components.begin(), m_components.end(), component);

	if (it != m_components.end())
		m_components.erase(it);
}