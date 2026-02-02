#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include <string>
struct Shop{
	bool hover;
	sf::Vector2f pos;
	sf::Vector2f size;

	sf::Texture* TX;
	sf::Texture* TX2;

	sf::RectangleShape* shop;

	Shop();
	Shop(float posX_, float posY_, float sizeX, float sizeY);
	virtual ~Shop();

	virtual void renderShop(sf::RenderWindow& window);
	virtual void updateShop(float dt);

};

