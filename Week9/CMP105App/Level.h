#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "BallManager.h"
#include "BallManager2.h"
#include "Player.h"
#include "BulletManager.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	BallManager ballManager;
	BallManager2 ballManager2;

	Player player;
	sf::Texture playerTexture;

	BulletManager bulletManager;
	bool shoot;
};