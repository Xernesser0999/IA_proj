#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) {
    createGameObjects();
}

Morning::~Morning() {

}

void Morning::createGameObjects() {
    test = new Baker(0, 500, 100, 100, 300.0f, "sprite/player.png");
    npc = new Npc(0, 800, 100, 100, 300.0f, "sprite/player.png");
    npc1 = new Npc(1000, 900, 100, 100, 300.0f, "sprite/player.png");
    npc2 = new Npc(1500, 950, 100, 100, 300.0f, "sprite/player.png");
    bakery = new Bakery(0, 0, 400, 400);
    store = new Store(450, 0, 400, 400);
    candy_shop = new CandyShop(900, 0, 400, 400);
    npcBt = new NpcBehaviourTree(npc);
    btClock = Clock(true);
}

void Morning::displayScene(sf::RenderWindow& window) {
    store->renderShop(window);
    bakery->renderShop(window);
    candy_shop->renderShop(window);
    test->render(window);
    npc->render(window);
    npc1->render(window);
    npc2->render(window);
}

void Morning::update(const bool* keys, float dt) {
    bakery->updateShop(dt);
    store->updateShop(dt);
    candy_shop->updateShop(dt);
    test->update(dt, nullptr);
    npc->update(dt, bakery);
    npc1->update(dt, store);
    npc2->update(dt, candy_shop);

    if (BehaviourTree::blackBoard == nullptr) {
        BehaviourTree::blackBoard = new NpcBlackBoard();
    }
    auto blackBoardElt = static_cast<NpcBlackBoard*>(BehaviourTree::blackBoard);
    blackBoardElt->coorNpcX = static_cast<int>(npc->posX);
    blackBoardElt->coorNpcY = static_cast<int>(npc->posY);
    blackBoardElt->shopCoorX = static_cast<int>(bakery->pos.x + bakery->size.x - 300);
    blackBoardElt->shopCoorY = static_cast<int>(bakery->pos.y + bakery->size.y - 80);

    npcBt->execute();
    float btdt = btClock.getElapsedTime();
    npcBt->tick(btdt);
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
        currentScene = SceneState::menu;
    }
}
