#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) : npcBlackboard(nullptr) {
    createGameObjects();
}

Morning::~Morning() {
    delete npcBlackboard;
    npcBlackboard = nullptr;
}

void Morning::createGameObjects() {
    test = new Baker(0, 500, 100, 100, 300.0f, "sprite/player.png");
    npc = new Npc(0, 800, 100, 100, 300.0f, "sprite/player.png");
    /*npc1 = new Npc(1000, 900, 200, 200, 300.0f, "sprite/player.png");
    npc2 = new Npc(1500, 950, 100, 100, 300.0f, "sprite/player.png");*/
    bakery = new Bakery(0, 0, 400, 400);
    store = new Store(450, 0, 400, 400);
    candy_shop = new CandyShop(900, 0, 400, 400);

    npcBlackboard = new NpcBlackBoard();
    npcBlackboard->coorNpcX = npc->posX;
    npcBlackboard->coorNpcY = npc->posY;
    npcBlackboard->shopCoorX = bakery->pos.x + bakery->size.x - 100;
    npcBlackboard->shopCoorY = bakery->pos.y + bakery->size.y - 100;
    npc->bt = npcBlackboard;
    npcBt = new NpcBehaviourTree(npc);
    npcBt->buildTree();
    btClock = Clock(true);
    npcBt->setBlackboard(npcBlackboard);
    npcBt->execute();
}

void Morning::displayScene(sf::RenderWindow& window) {
    store->renderShop(window);
    bakery->renderShop(window);
    candy_shop->renderShop(window);
    test->render(window);
    npc->render(window);
    /*npc1->render(window);
    npc2->render(window);*/
}

void Morning::update(const bool* keys, float dt) {
    bakery->updateShop(dt);
    store->updateShop(dt);
    candy_shop->updateShop(dt);
    test->update(dt, nullptr);
    float btdt = btClock.getElapsedTime();
    npcBt->tick(btdt);
    npc->update(dt, bakery);
    /*npc1->update(dt, store);
    npc2->update(dt, candy_shop);*/

    
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
        currentScene = SceneState::menu;
    }
}
