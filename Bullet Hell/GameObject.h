#pragma once
#include <vector>
#include <memory>
#include <string>
#include <Renderer2D.h>
#include "MathLibrary.h"

class Component;

class GameObject
{
public:
	GameObject() {}
	virtual ~GameObject();

	bool isActive() const { return m_active; }
	void setActiveState(bool state);

	//Updating and drawing

	void update(float deltaTime);
	void updateTransform();
	virtual void onUpdate(float deltaTime) {};

	void draw(aie::Renderer2D* renderer);
	virtual void onDraw(aie::Renderer2D* renderer) {};

	//Transform

	const Matrix3& getLocalTransform() const { return m_localTransform; }
	const Matrix3& getGlobalTransform() const { return m_globalTransform; }
	float* getLocalTransformFloat() const { return (float*)&m_localTransform; }
	float* getGlobalTransformFloat() const { return (float*)&m_globalTransform; }

	void setLocalTransform(const Matrix3& m);
	void setGlobalTransform(const Matrix3& m);
	void setPosition(float x, float y);
	void setPosition(const Vector2& v);
	void setRotation(float radians);
	void setScale(float wMultiplier, float hMultiplier);
	void setScale(float multiplier);
	void move(float x, float y);
	void move(const Vector2& v);
	void rotate(float radians);
	void scale(float wMultiplier, float hMultiplier);
	void scale(float multiplier);

	//Hierarchy

	GameObject* getParent() const { return m_parent; }
	GameObject* getChild(unsigned int index) const { return m_children[index]; }

	size_t childCount() const { return m_children.size(); }

	void addChild(GameObject* child);
	void removeChild(GameObject* child);

	//Components

	void addComponent(const std::shared_ptr<Component>& component);
	void removeComponent(const std::shared_ptr<Component>& component);

	void allComponentsOn();
	void allComponentsOff();

protected:
	bool m_active = true;

	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;

	GameObject* m_parent = nullptr;
	std::vector<GameObject*> m_children;

	std::vector<std::shared_ptr<Component>> m_components;
};

class Component
{
public:
	virtual ~Component() {}

	virtual void update(GameObject* gameObject, float deltaTime) = 0;
	virtual void draw(GameObject* gameObject, aie::Renderer2D* renderer) = 0;
	
	bool isActive() const { return m_active; }
	void setActiveState(bool state) { m_active = state; }

protected:
	bool m_active = true;
};