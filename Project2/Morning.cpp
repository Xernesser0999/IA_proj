#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) {
    createGameObjects();
}

Morning::~Morning() {

}

void Morning::createGameObjects() {
    test = new Baker(0, 500, 100, 100, 300.0f, "sprite/player.png");
    npc = new Npc(0, 900, 100, 100, 300.0f, "sprite/player.png");
    bakery = new Bakery(0, 0, 400, 400, "sprite/bakery.png");
    bakery2 = new Bakery(450, 0, 400, 400, "sprite/store.png");
}

void Morning::displayScene(sf::RenderWindow& window) {
    test->render(window);
    npc->render(window);
    bakery->renderShop(window);
    bakery2->renderShop(window);
}

void Morning::update(const bool* keys, float dt) {
    test->update(dt, nullptr);
    npc->update(dt, bakery2);
    bakery->updateShop(dt);
    bakery2->updateShop(dt);
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
        currentScene = SceneState::menu;
    }
}
