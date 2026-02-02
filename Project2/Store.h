#pragma once
#include "Shop.h"

class Store : public Shop {
public:
	Store();
	Store(float posX_, float posY_, float sizeX, float sizeY);

	void updateShop(float dt) override;
	void renderShop(sf::RenderWindow& window) override;

};

