#pragma once
#include "GameObjects.h"

class CandyShop : public GameObjects {
public:
	CandyShop();
	CandyShop(float posX_, float posY_, float sizeX, float sizeY);

	void updateGameObject(float dt) override;
	void renderGameObject(sf::RenderWindow& window) override;

};
