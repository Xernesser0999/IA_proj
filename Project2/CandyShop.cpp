#include "CandyShop.h"

CandyShop::CandyShop(){
}

CandyShop::CandyShop(float posX_, float posY_, float sizeX, float sizeY) : GameObjects(posX_, posY_, sizeX, sizeY) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/candy_store.png");
	shop->setTexture(TX);
}

void CandyShop::updateGameObject(float dt){
}

void CandyShop::renderGameObject(sf::RenderWindow& window){
	window.draw(*shop);
}
