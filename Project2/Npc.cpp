#include "Npc.h"

Npc::Npc() {
}

Npc::Npc(float posX_, float posY_, float sizeX, float sizeY, float speed_, std::string file) : Pawn(posX_, posY_, sizeX, sizeY, speed_, file) {
}

void Npc::update(float dt, Bakery* shop) {
	shop_ = shop;

	if (!arrived) {
		moveTo(dt, shop_);
	}

	pos = { posX, posY };
	rectangle->setPosition(pos);
}

void Npc::moveTo(float dt, Bakery* shop) {
	float targetX = shop->pos.x + (shop->size.x/2);
	float targetY = shop->pos.y + shop->size.y;

	if (posX == targetX && posY == targetY) {
		arrived = true;
		return;
	}

	if (posX < targetX) {
		posX += speed * dt;
		if (posX > targetX) {
			posX = targetX;
		}
	}
	else if (posX > targetX) {
		posX -= speed * dt;
		if (posX < targetX) { 
			posX = targetX;
		}
	}
	else if (posY < targetY) {
		posY += speed * dt;
		if (posY > targetY) {
			posY = targetY;
		}
	}
	else if (posY > targetY) {
		posY -= speed * dt;
		if (posY < targetY) {
			posY = targetY;
		}
	}
}