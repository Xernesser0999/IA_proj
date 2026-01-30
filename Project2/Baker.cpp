#include "Baker.h"

Baker::Baker(){
}

Baker::Baker(float posX_, float posY_, std::string file) : Pawn(posX_, posY_, file) {
}

void Baker::update(float dt) {
	sprite->setPosition(pos);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
		posX += 1;
		if (posX >= 1920) {
			direction = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
		posX -= 1;
		if (posX <= 0) {
			direction = true;
		}
	}

	pos = {posX, posY};
}