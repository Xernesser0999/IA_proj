#include "Pawn.h"

Pawn::Pawn() {
}

Pawn::Pawn(float posX_, float posY_, std::string file) {
	posX = posX_;
	posY = posY_;
	pos = { posX_, posY_ };
	
	TX = new sf::Texture(file.c_str());
	sprite = new sf::Sprite(*TX);
}

Pawn::~Pawn() {
	TX = nullptr;
	sprite = nullptr;
	delete TX;
	delete sprite;
}

void Pawn::update(float dt) {

}

void Pawn::render(sf::RenderWindow& window) {
	window.draw(*sprite);
}

void Pawn::moneyAdd(float change) {
	money += change;
}

void Pawn::moneySubstract(float change) {
	money -= change;
}