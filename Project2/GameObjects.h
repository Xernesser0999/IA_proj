#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include <string>
class GameObjects{
public:
	GameObjects();
	GameObjects(float posX_, float posY_, float sizeX, float sizeY);
	virtual ~GameObjects();

	virtual void renderGameObject(sf::RenderWindow& window);
	virtual void updateGameObject(float dt);

public:
	bool hover;
	sf::Vector2f pos;
	sf::Vector2f size;

	sf::Texture* TX;
	sf::Texture* TX2;

	sf::RectangleShape* shop;
};

