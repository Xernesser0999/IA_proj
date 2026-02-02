#include "Shop.h"

Shop::Shop(){
}

Shop::Shop(float posX_, float posY_, float sizeX, float sizeY){
    pos = { posX_, posY_ };
    size = { sizeX, sizeY };
    
    shop = new sf::RectangleShape(size);
    shop->setPosition(pos);
}

Shop::~Shop(){

}

void Shop::renderShop(sf::RenderWindow& window){
    window.draw(*shop);
}

void Shop::updateShop(float dt){

}
