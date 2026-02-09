#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) : npcBlackboard(nullptr) {
    createGameObjects();
}

Morning::~Morning() {
    delete npcBlackboard;
    npcBlackboard = nullptr;
}

void Morning::createGameObjects() {
    bakery = new Bakery(0, 0, 400, 400);
    shopVec.push_back(bakery);
    store = new Store(450, 0, 400, 400);
    shopVec.push_back(store);
    candy_shop = new CandyShop(900, 0, 400, 400);
    shopVec.push_back(candy_shop);

    clockSpawn = spawn.restart().asSeconds();
    srand(time(0));
    int Random = rand() % 2;
    npc = new Npc(0, 800, 100, 100, 300.0f, "sprite/player.png");
    npcBlackboard = new NpcBlackBoard();
    npcBlackboard->coorNpcX = npc->posX;
    npcBlackboard->coorNpcY = npc->posY;
    npcBlackboard->shopCoorX = shopVec[Random]->pos.x + shopVec[Random]->size.x - 100;
    npcBlackboard->shopCoorY = shopVec[Random]->pos.y + shopVec[Random]->size.y - 100;
    npc->bt = npcBlackboard;
    npcBt = new NpcBehaviourTree(npc);
    npcBt->buildTree();
    npcBt->setBlackboard(npcBlackboard);
    npcBt->execute();
}

void Morning::displayScene(sf::RenderWindow& window) {
    store->renderShop(window);
    bakery->renderShop(window);
    candy_shop->renderShop(window);
    npc->render(window);
}

void Morning::update(float dt) {
    bakery->updateShop(dt);
    store->updateShop(dt);
    candy_shop->updateShop(dt);
    npcBt->tick(dt);
    npc->update(dt, bakery);

    
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
        currentScene = SceneState::menu;
    }
}
