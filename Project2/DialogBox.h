#pragma once
#include "GameObjects.h"

class DialogBox : public GameObjects{
public:
	DialogBox();
	DialogBox(float posX_, float posY_, float sizeX, float sizeY);

	void updateGameObject(float dt) override;
	void renderGameObject(sf::RenderWindow& window) override;

public:

	sf::RectangleShape* dialog;
};

