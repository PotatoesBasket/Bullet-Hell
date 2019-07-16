#include "GameObject.h"

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

void GameObject::update(float deltaTime)
{
	onUpdate(deltaTime);

	for (auto child : m_children)
		child->update(deltaTime);
}

void GameObject::updateTransform()
{
	if (m_parent != nullptr)
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	else
		m_globalTransform = m_localTransform;

	for (auto child : m_children)
		child->updateTransform();
}

void GameObject::draw(aie::Renderer2D * renderer)
{
	onDraw(renderer);

	for (auto child : m_children)
		child->draw(renderer);
}

void GameObject::setPosition(float x, float y)
{
	m_localTransform.translation = { x, y, 1 };
	updateTransform();
}

void GameObject::setRotation(float radians)
{
	m_localTransform.setRotateZ(radians);
	updateTransform();
}

void GameObject::setScale(float width, float height)
{
	m_localTransform.setScaled(width, height, 1);
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

void GameObject::scale(float width, float height)
{
	m_localTransform.scale(width, height, 1);
	updateTransform();
}

void GameObject::scale(const Vector2& v)
{
	m_localTransform.scale(Vector3(v.x, v.y, 1));
	updateTransform();
}