#include "Player.h"
#include "Defines.h"
#include <Input.h>

Player::Player(const char* texture, Vector2 startPos)
{
	setPosition(startPos);

	m_sprite = std::make_shared<Sprite>(texture);
	addComponent(m_sprite);
	
	m_boundary = std::make_shared<BoxBoundary>(
		startPos - Vector2(m_width * 0.5f, m_height * 0.5f),
		startPos + Vector2(m_width * 0.5f, m_height * 0.5f));
	addComponent(m_boundary);

	m_hurtbox = std::make_shared<CircleBoundary>(startPos, m_hurtRadius);
	addComponent(m_hurtbox);
}

void Player::onUpdate(float deltaTime)
{
	if (m_localTransform.translation.x < 0 + m_boundary.get()->width() * 0.5f)
		m_localTransform.translation.x = 0 + m_boundary.get()->width() * 0.5f;
	if (m_localTransform.translation.x > SCR_WIDTH - m_boundary.get()->width() * 0.5f)
		m_localTransform.translation.x = SCR_WIDTH - m_boundary.get()->width() * 0.5f;
	if (m_localTransform.translation.y < 0 + m_boundary.get()->height() * 0.5f)
		m_localTransform.translation.y = 0 + m_boundary.get()->height() * 0.5f;
	if (m_localTransform.translation.y > SCR_HEIGHT - m_boundary.get()->height() * 0.5f)
		m_localTransform.translation.y = SCR_HEIGHT - m_boundary.get()->height() * 0.5f;

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		move(Vector2(1, 0) * deltaTime * m_speed);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		move(Vector2(-1, 0) * deltaTime * m_speed);
	}

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		move(Vector2(0, 1) * deltaTime * m_speed);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		move(Vector2(0, -1) * deltaTime * m_speed);
	}
}