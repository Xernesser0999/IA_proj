#include "Pawn.h"

Pawn::Pawn(float posX_, float posY_, std::string file) {
	posX = posX_;
	posY = posY_;
	pos = { posX_, posY_ };
	
	TX = new sf::Texture(file.c_str());
	sprite = new sf::Sprite(*TX);
}

Pawn::~Pawn() {
	delete TX;
	delete sprite;

	TX = nullptr;
	sprite = nullptr;
}

void Pawn::update(float dt) {

}

void Pawn::render(sf::RenderWindow& window) {
	window.draw(*sprite);
}

Pawn::Pawn()
{
}

void Pawn::moneyAdd(float change) {
	money += change;
}

void Pawn::moneySubstract(float change) {
	money -= change;
}