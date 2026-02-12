#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "Bakery.h"

#include <string>

class Pawn {
public:
	Pawn();
	Pawn(float posX_, float posY_, float sizeX_, float sizeY_, float speed_, std::string file);
	virtual ~Pawn();

	virtual void update(float dt, GameObjects* shop);
	void render(sf::RenderWindow& window);

	void moneyAdd(float change);
	void moneySubstract(float change);

public:
	float posX;
	float posY;
	float sizeX;
	float sizeY;
	float speed;

	sf::Vector2f pos;
	sf::Vector2f size;

	float money;
	float productPrice;

	sf::Texture* TX;
	sf::RectangleShape* rectangle;
};

