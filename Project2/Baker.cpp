#include "Baker.h"

Baker::Baker(float posX_, float posY_, std::string file) : pawn(posX_, posY_, file) 
{

}

void Baker::update(float dt) {
	sprite->setPosition(pos);


	if (direction == true) {
		posX += 1;
		if (posX >= 1920) {
			direction = false;
		}
	}
	else {
		posX -= 1;
		if (posX <= 0) {
			direction = true;
		}
	}


	pos = {posX, posY};
}