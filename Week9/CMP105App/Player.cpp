#include "Player.h"

Player::Player()
{
	window = nullptr;
}

Player::~Player()
{

}

void Player::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity.y -= 500;
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y += 500;
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x -= 500;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x += 500;
	}
}

void Player::update(float dt)
{
	move(velocity * dt);
	velocity = sf::Vector2f(0, 0);
}