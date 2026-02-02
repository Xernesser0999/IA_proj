#pragma once
#include "Shop.h"

class CandyShop : public Shop {
public:
	CandyShop();
	CandyShop(float posX_, float posY_, float sizeX, float sizeY);

	void updateShop(float dt) override;
	void renderShop(sf::RenderWindow& window) override;

};
