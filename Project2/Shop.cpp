#include "Shop.h"

Shop::Shop(){
}

Shop::Shop(float posX_, float posY_, float sizeX, float sizeY, std::string file){
    pos = { posX_, posY_ };
    size = { sizeX, sizeY };
    
    TX = new sf::Texture();
    TX->loadFromFile(file);

    shop = new sf::RectangleShape(size);
    shop->setPosition(pos);
    shop->setTexture(TX);
}

Shop::~Shop(){

}

void Shop::renderShop(sf::RenderWindow& window){
    window.draw(*shop);
}

void Shop::updateShop(float dt){

}
