#pragma once
#include "GameObjects.h"

class Bakery : public GameObjects {
public:
	Bakery();
	Bakery(float posX_, float posY_, float sizeX, float sizeY);

	void updateGameObject(float dt) override;
	void renderGameObject(sf::RenderWindow& window) override;

};

