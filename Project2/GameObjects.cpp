#include "GameObjects.h"

GameObjects::GameObjects(){
}

GameObjects::GameObjects(float posX_, float posY_, float sizeX, float sizeY){
    pos = { posX_, posY_ };
    size = { sizeX, sizeY };
    
    shop = new sf::RectangleShape(size);
    shop->setPosition(pos);
}

GameObjects::~GameObjects(){

}

void GameObjects::renderGameObject(sf::RenderWindow& window){
    window.draw(*shop);
}

void GameObjects::updateGameObject(float dt){

}
