#include "Baker.h"

Baker::Baker(float posX_, float posY_, std::string file) : pawn(posX_, posY_, file) 
{

}

void Baker::update(float dt) {
	sprite->setPosition(pos);
	posX += 1;
	pos = {posX, posY};
}