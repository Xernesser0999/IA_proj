#include "Baker.h"

Baker::Baker(){
}

Baker::Baker(float posX_, float posY_, float sizeX, float siezY, std::string file) : Pawn(posX_, posY_, sizeX, sizeY, file) {
}

void Baker::update(float dt) {
	rectangle->setPosition(pos);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
		posX += 1;
		if (posX >= 1920) {
			posX = 1920 - 100;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
		posX -= 1;
		if (posX <= 0) {
			posX = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
		posY -= 1;
		if (posY <= 0) {
			posY = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
		posY += 1;
		if (posY >= 1080) {
			posY = 1080 + 100;
		}
	}

	pos = {posX, posY};
}