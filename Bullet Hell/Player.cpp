#include "Player.h"
#include <Input.h>

Player::Player(Point2D position, char* filename, int maxHealth) :
	Character(position, filename, maxHealth)
{
	
}

Player::~Player()
{
	delete m_texture;
}

void Player::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_acceleration.x += 0.05f;

		if (m_acceleration.x > 50)
			m_acceleration.x = 50;

		m_velocity.x += m_acceleration.x;

		if (m_velocity.x > m_maxVelocity)
			m_velocity.x = m_maxVelocity;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_acceleration.x += 0.05f;

		if (m_acceleration.x > 50)
			m_acceleration.x = 50;

		m_velocity.x -= m_acceleration.x;

		if (m_velocity.x < -m_maxVelocity)
			m_velocity.x = -m_maxVelocity;
	}
	else
	{
		if (m_acceleration.x > 0)
			m_acceleration.x -= 0.1f;
		
		if (m_acceleration.x < 0)
			m_acceleration.x = 0;

		m_velocity.x = 0;
	}

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_acceleration.y += 0.05f;

		if (m_acceleration.y > 50)
			m_acceleration.y = 50;

		m_velocity.y += m_acceleration.y;

		if (m_velocity.y > m_maxVelocity)
			m_velocity.y = m_maxVelocity;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_acceleration.y += 0.05f;

		if (m_acceleration.y > 50)
			m_acceleration.y = 50;

		m_velocity.y -= m_acceleration.y;

		if (m_velocity.y < -m_maxVelocity)
			m_velocity.y = -m_maxVelocity;
	}
	else
	{
		if (m_acceleration.y > 0)
			m_acceleration.y -= 0.1f;

		if (m_acceleration.y < 0)
			m_acceleration.y = 0;
	}

	m_position += m_velocity * deltaTime;
}

void Player::draw(aie::Renderer2D* renderer)
{
	renderer->drawCircle(m_position.x, m_position.y, 20, 0);
	renderer->drawSprite(m_texture, 600, 500, 80, 93, 0, 1, 0.5f, 0.5f);
}