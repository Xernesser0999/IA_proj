#include "Store.h"

Store::Store(){
}

Store::Store(float posX_, float posY_, float sizeX, float sizeY) : GameObjects(posX_, posY_, sizeX, sizeY) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/store.png");
	shop->setTexture(TX);

	initShopTree(5);

}

void Store::updateGameObject(float dt){
	GameObjects::updateGameObject(dt);
}

void Store::renderGameObject(sf::RenderWindow& window) {
	window.draw(*shop);
}
