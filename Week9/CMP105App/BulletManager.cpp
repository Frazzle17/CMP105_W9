#include "BulletManager.h"
#include <iostream>
BulletManager::BulletManager()
{
	window = nullptr;
	player = nullptr;
	bulletTexture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 5; i++)
	{
		bullets.push_back(Ball());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&bulletTexture);
		bullets[i].setSize(sf::Vector2f(50, 50));
	}
}

BulletManager::~BulletManager()
{

}

void BulletManager::update(float dt)
{
	int noBullets = 0;
	spawnPoint = sf::Vector2f(player->getPosition().x + (player->getSize().x / 2), player->getPosition().y + (player->getSize().y / 2));
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			noBullets += 1;
			bullets[i].update(dt);
		}
	}
	deathCheck();
	std::cout << noBullets << std::endl;
}

void BulletManager::spawn()
{
	direction = sf::Vector2f(player->getPosition().x + (player->getSize().x / 2), player->getPosition().y + (player->getSize().y / 2)) - sf::Vector2f(input->getMouseX(), input->getMouseY());
	direction = Vector::normalise(direction);
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive())
		{
			bullets[i].setAlive(true);
			bullets[i].setVelocity(sf::Vector2f(-1000 * direction.x, -1000 * direction.y));
			bullets[i].setPosition(spawnPoint - sf::Vector2f(bullets[i].getSize().x / 2, bullets[i].getSize().y / 2));
			return;
		}
	}
	bullets.push_back(Ball());
	bullets[bullets.size() - 1].setAlive(true);
	bullets[bullets.size() - 1].setTexture(&bulletTexture);
	bullets[bullets.size() - 1].setSize(sf::Vector2f(50, 50));
	bullets[bullets.size() - 1].setVelocity(sf::Vector2f(-1000 * direction.x, -1000 * direction.y));
	bullets[bullets.size() - 1].setPosition(spawnPoint);
	return;
}

void BulletManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].getPosition().x < 0 - bullets[i].getSize().x)
		{
			bullets[i].setAlive(false);
		}
		if (bullets[i].getPosition().x > window->getSize().x)
		{
			bullets[i].setAlive(false);
		}
		if (bullets[i].getPosition().y < 0 - bullets[i].getSize().y)
		{
			bullets[i].setAlive(false);
		}
		if (bullets[i].getPosition().y > window->getSize().y)
		{
			bullets[i].setAlive(false);
		}
	}
}

void BulletManager::render()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			window->draw(bullets[i]);
		}
	}
}