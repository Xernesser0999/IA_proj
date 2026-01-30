#include "Npc.h"

Npc::Npc(){

}

Npc::Npc(float posX_, float posY_, float sizeX, float sizeY, float speed_, std::string file) : Pawn(posX_, posY_, sizeX, sizeY, speed_, file) {

}

void Npc::update(float dt, Bakery* shop) {
	shop_ = shop;
	rectangle->setPosition(pos);
	while (!arrived) {
		
		this->moveTo(dt, shop_);
	}
}

void Npc::moveTo(float dt, Bakery* shop){
	if (posX <= shop->pos.x) {
		posX += 200;
	}
	else if  (posX == shop -> pos.x && posY <= shop->pos.y) {
		posY += speed * dt;
	}
	else {
		arrived = true;
	}
}
