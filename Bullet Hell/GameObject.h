#pragma once
#include <vector>
#include <Renderer2D.h>
#include <MathLibrary.h>

class GameObject
{
public:
	GameObject() {}
	virtual ~GameObject()
	{
		if (m_parent != nullptr)
			m_parent->removeChild(this);

		for (auto child : m_children)
			child->m_parent = nullptr;
	}

	GameObject* getParent() const { return m_parent; }
	GameObject* getChild(unsigned int index) const { return m_children[index]; }
	const Matrix3& getLocalTransform() const { return m_localTransform; }
	const Matrix3& getGlobalTransform() const { return m_globalTransform; }

	unsigned int childCount() const { return m_children.size(); }

	void addChild(GameObject* child);
	void removeChild(GameObject* child);

	void update(float deltaTime);
	void updateTransform();
	virtual void onUpdate(float deltaTime) {};

	void draw(aie::Renderer2D* renderer);
	virtual void onDraw(aie::Renderer2D* renderer) {};

	void setPosition(float x, float y);
	void setRotation(float radians);
	void setScale(float width, float height);
	void move(float x, float y);
	void move(const Vector2& v);
	void rotate(float radians);
	void scale(float width, float height);
	void scale(const Vector2& v);

protected:
	GameObject* m_parent = nullptr;
	std::vector<GameObject*> m_children;

	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;
};