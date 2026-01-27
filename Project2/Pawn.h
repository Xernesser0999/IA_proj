#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include <string>

struct pawn {
	float posX;
	float posY;
	sf::Vector2f pos;

	sf::Texture* TX;
	sf::Sprite* sprite;

	pawn(float posX_, float posY_, std::string file);
	virtual ~pawn();

	virtual void update(float dt);
	void render(sf::RenderWindow& window);
};

