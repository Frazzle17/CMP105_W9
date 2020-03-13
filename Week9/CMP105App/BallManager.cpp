#include "BallManager.h"
#include <iostream>

BallManager::BallManager()
{
	window = nullptr;
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&ballTexture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BallManager::~BallManager()
{

}

void BallManager::update(float dt)
{
	int noBalls = 0;
	spawnPoint = sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2);
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			noBalls += 1;
			balls[i].update(dt);
		}
	}
	deathCheck();
	std::cout << noBalls << "  ";
}

void BallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(sf::Vector2f(rand() % 200 - 100, rand() % 200 - 100));
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
	balls.push_back(Ball());
	balls[balls.size() - 1].setAlive(true);
	balls[balls.size() - 1].setTexture(&ballTexture);
	balls[balls.size() - 1].setSize(sf::Vector2f(100, 100));
	balls[balls.size() - 1].setVelocity(sf::Vector2f(rand() % 200 - 100, rand() % 200 - 100));
	balls[balls.size() - 1].setPosition(spawnPoint);
	return;
}

void BallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].getPosition().x < 0 - balls[i].getSize().x)
		{
			balls[i].setAlive(false);
		}
		if (balls[i].getPosition().x > window->getSize().x)
		{
			balls[i].setAlive(false);
		}
		if (balls[i].getPosition().y < 0 - balls[i].getSize().y)
		{
			balls[i].setAlive(false);
		}
		if (balls[i].getPosition().y > window->getSize().y)
		{
			balls[i].setAlive(false);
		}
	}
}

void BallManager::render()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}