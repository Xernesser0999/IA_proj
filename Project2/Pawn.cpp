#include "Pawn.h"

Pawn::Pawn() {
}

Pawn::Pawn(float posX_, float posY_, float sizeX_, float sizeY_, std::string file) {
	posX = posX_;
	posY = posY_;
	sizeX = sizeX_;
	sizeY = sizeY_;
	pos = { posX_, posY_ };
	pos = { sizeX_, sizeY_};

	TX = new sf::Texture(file.c_str());
	rectangle = new sf::RectangleShape(size);
	rectangle->setPosition(pos);
	rectangle->setTexture(TX);
}

Pawn::~Pawn() {
	TX = nullptr;
	rectangle = nullptr;
	delete TX;
	delete rectangle;
}

void Pawn::update(float dt) {

}

void Pawn::render(sf::RenderWindow& window) {
	window.draw(*rectangle);
}

void Pawn::moneyAdd(float change) {
	money += change;
}

void Pawn::moneySubstract(float change) {
	money -= change;
}