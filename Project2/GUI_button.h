#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include <string>

class GUI_button {
	float posX;
	float posY;
	sf::Vector2f pos;

	sf::Texture* TX;
	sf::Sprite* sprite;

	GUI_button(float posX_, float posY_, std::string file);
	~GUI_button();

	void render(sf::RenderWindow& window);

	bool hovered();
	bool clicked();
};

