#pragma once
#include "GameObjects.h"

class Store : public GameObjects {
public:
	Store();
	Store(float posX_, float posY_, float sizeX, float sizeY);

	void updateGameObject(float dt) override;
	void renderGameObject(sf::RenderWindow& window) override;

};

