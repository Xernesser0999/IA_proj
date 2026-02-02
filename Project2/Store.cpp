#include "Store.h"

Store::Store(){
}

Store::Store(float posX_, float posY_, float sizeX, float sizeY) : Shop(posX_, posY_, sizeX, sizeY) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/store.png");
	shop->setTexture(TX);
}

void Store::updateShop(float dt){
}

void Store::renderShop(sf::RenderWindow& window) {
	window.draw(*shop);
}
