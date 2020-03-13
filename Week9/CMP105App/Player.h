#pragma once
#include "Framework/GameObject.h"
class Player:public GameObject
{
public:
	Player();
	~Player();

	virtual void handleInput();
	virtual void update(float dt);
	void setWindow(sf::RenderWindow* win) { window = win; };

protected:
	sf::RenderWindow* window;
};

