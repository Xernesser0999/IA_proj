#include "GameObjects.h"
#include "BehaviourTree.h"

GameObjects::GameObjects(){
}

GameObjects::GameObjects(float posX_, float posY_, float sizeX, float sizeY){
    pos = { posX_, posY_ };
    size = { sizeX, sizeY };
    
    shop = new sf::RectangleShape(size);
    shop->setPosition(pos);
}

GameObjects::~GameObjects(){
    delete shopTree;
    shopTree = nullptr;
    delete shopBb;
    shopBb = nullptr;
}

void GameObjects::renderGameObject(sf::RenderWindow& window){
    window.draw(*shop);
}

void GameObjects::updateGameObject(float dt){
    if(shopTree != nullptr){
        shopTree->tick(dt);
	}
}

void GameObjects::requestItem(){
    if (shopBb != nullptr) {
        shopBb->result = false;
        shopBb->sale = false;
        shopBb->npcRequest = true;
	}
}

void GameObjects::initShopTree(int startingStock_){
    startingStock = startingStock_;
	shopBb = new ShopBlackBoard();
	shopBb->stock = startingStock;
	shopTree = new ShopTree(this);
	shopTree->setBlackboard(shopBb);
	shopTree->buildTree();
	shopTree->execute();
}
