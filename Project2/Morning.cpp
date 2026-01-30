#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) {
    createGameObjects();
}

Morning::~Morning() {

}

void Morning::createGameObjects() {
    test = new Baker(0, 500, "pp.png");
    bakery = new Bakery(0, 0, 500, 500, "pp_hover.png");
}

void Morning::displayScene(sf::RenderWindow& window) {
    test->render(window);
    bakery->renderShop(window);
}

void Morning::update(const bool* keys, float dt) {
	test->update(dt);
    bakery->updateShop(dt);
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
        currentScene = SceneState::menu;
    }
}
