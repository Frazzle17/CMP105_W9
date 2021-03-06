#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballManager.setWindow(window);
	ballManager.setSpawnPoint(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
	ballManager2.setWindow(window);
	ballManager2.setSpawnPoint(sf::Vector2f(rand() % window->getSize().x, 0));

	playerTexture.loadFromFile("gfx/MushroomTrans.png");
	player.setTexture(&playerTexture);
	player.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	player.setSize(sf::Vector2f(100, 100));
	player.setInput(input);

	bulletManager.setWindow(window);
	bulletManager.setInput(input);
	Player* play = &player;
	bulletManager.setPlayer(play);
	bulletManager.setSpawnPoint(sf::Vector2f(player.getPosition().x + (player.getSize().x / 2), player.getPosition().y + (player.getSize().y / 2)));
	shoot = false;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Num1))
	{
		input->setKeyUp(sf::Keyboard::Num1);
		ballManager.spawn();
	}
	if (input->isKeyDown(sf::Keyboard::Num2))
	{
		input->setKeyUp(sf::Keyboard::Num2);
		ballManager2.spawn();
	}
	player.handleInput();
	if (input->isMouseLDown() && shoot == false)
	{
		bulletManager.spawn();
		shoot = true;
	}
	if (!input->isMouseLDown())
	{
		shoot = false;
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
	ballManager2.update(dt);
	player.update(dt);
	bulletManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	ballManager.render();
	ballManager2.render();
	window->draw(player);
	bulletManager.render();

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}