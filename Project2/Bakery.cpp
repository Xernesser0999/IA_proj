#include "Bakery.h"

Bakery::Bakery(){
}

Bakery::Bakery(float posX_, float posY_, float sizeX, float sizeY) : GameObjects(posX_, posY_, sizeX, sizeY) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/bakery.png");
	shop->setTexture(TX);

	initShopTree(10);
}

void Bakery::updateGameObject(float dt) {
	GameObjects::updateGameObject(dt);
}

void Bakery::renderGameObject(sf::RenderWindow& window) {
	window.draw(*shop);
}
