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
		velocity.y -= 100;
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y += 100;
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x -= 100;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x += 100;
	}
}

void Player::update(float dt)
{
	move(velocity * dt);
}