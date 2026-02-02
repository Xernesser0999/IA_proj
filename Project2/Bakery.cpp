#include "Bakery.h"

Bakery::Bakery(){
}

Bakery::Bakery(float posX_, float posY_, float sizeX, float sizeY) :  Shop(posX_, posY_, sizeX, sizeY) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/bakery.png");
	shop->setTexture(TX);
}

void Bakery::updateShop(float dt){
}

void Bakery::renderShop(sf::RenderWindow& window){
	window.draw(*shop);
}
