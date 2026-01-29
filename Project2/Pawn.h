#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include <string>

struct Pawn {
	float posX;
	float posY;
	sf::Vector2f pos;

	float money;
	float productPrice;

	sf::Texture* TX;
	sf::Sprite* sprite;

	Pawn();
	Pawn(float posX_, float posY_, std::string file);
	virtual ~Pawn();

	virtual void update(float dt);
	void render(sf::RenderWindow& window);

	void moneyAdd(float change);
	void moneySubstract(float change);
};

