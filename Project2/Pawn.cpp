#include "Pawn.h"

#include <SFML/Graphics.hpp>
#include <optional>

pawn::pawn(float posX_, float posY_, std::string file) {
	posX = posX_;
	posY = posY_;
	pos = { posX_, posY_ };
	
	TX = new sf::Texture(file.c_str());
	sprite = new sf::Sprite(*TX);
}

pawn::~pawn() {
	TX = nullptr;
	sprite = nullptr;

	delete TX;
	delete sprite;
}

void pawn::update(float dt) {
	//sprite->setPosition(pos);
	//posX += 1;
	//pos = {posX, posY};
}

void pawn::render(sf::RenderWindow& window) {
	window.draw(*sprite);
}