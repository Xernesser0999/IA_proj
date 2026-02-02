#pragma once
#include "Shop.h"

class Bakery : public Shop{
public:
	Bakery();
	Bakery(float posX_, float posY_, float sizeX, float sizeY);

	void updateShop(float dt) override;
	void renderShop(sf::RenderWindow& window) override;

};

