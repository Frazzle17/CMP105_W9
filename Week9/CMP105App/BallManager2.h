#pragma once
#include "Ball.h"
#include <vector>
#include <math.h>
class BallManager2
{
public:
	BallManager2();
	~BallManager2();

	void setWindow(sf::RenderWindow* win) { window = win; };

	void spawn();
	void deathCheck();
	void setSpawnPoint(sf::Vector2f newSpawnPoint) { spawnPoint = newSpawnPoint; };

	virtual void update(float dt);
	virtual void render();

protected:
	sf::RenderWindow* window;
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture ballTexture;
};

