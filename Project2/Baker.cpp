#include "Baker.h"

Baker::Baker(){
}

Baker::Baker(float posX_, float posY_, float sizeX, float sizeY, float speed_, std::string file) : Pawn(posX_, posY_, sizeX, sizeY, speed_, file) {
}

void Baker::update(float dt, Bakery* shop) {
	rectangle->setPosition(pos);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
		posX += speed * dt;
		if (posX >= 1920) {
			posX = 1920 - sizeX;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
		posX -= speed * dt;
		if (posX <= 0) {
			posX = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
		posY -= speed * dt;
		if (posY <= 0) {
			posY = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
		posY += speed * dt;
		if (posY >= 1080) {
			posY = 1080 - sizeY;
		}
	}

	pos = {posX, posY};
}