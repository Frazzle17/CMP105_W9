#pragma once
#include "Player.h"
#include "Ball.h"
#include "Framework/Input.h"
#include "Framework/Vector.h"
#include <vector>
#include <math.h>
class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void setWindow(sf::RenderWindow* win) { window = win; };
	void setInput(Input* in) { input = in; };
	void setPlayer(Player* play) { player = play; };

	void spawn();
	void deathCheck();
	void setSpawnPoint(sf::Vector2f newSpawnPoint) { spawnPoint = newSpawnPoint; };

	virtual void update(float dt);
	virtual void render();

protected:
	sf::RenderWindow* window;
	Input* input;
	Player* player;
	std::vector<Ball> bullets;
	sf::Vector2f spawnPoint;
	sf::Vector2f direction;
	sf::Texture bulletTexture;
};

