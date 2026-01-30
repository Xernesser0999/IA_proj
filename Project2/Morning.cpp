#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) {
    createGameObjects();
}

Morning::~Morning() {

}

void Morning::createGameObjects() {
    test = new Baker(0, 0, "pp.png");
}

void Morning::displayScene(sf::RenderWindow& window) {
    test->render(window);
}

void Morning::update(const bool* keys, float dt) {
	test->update(dt);
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
        currentScene = SceneState::menu;
    }
}
