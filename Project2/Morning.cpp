#include "Morning.h"

Morning::Morning(sf::RenderWindow& window) {
    createGameObjects();
}

Morning::~Morning() {

}

void Morning::createGameObjects() {
    test = new Baker(0, 0, "pp.png");
    sf::Font font("Pixellettersfull-BnJ5.ttf");
    sf::Text text(font);
    std::to_string(1);
    text.setString("TEST");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Regular | sf::Text::Underlined);
}

void Morning::displayScene(sf::RenderWindow& window) {
	test->render(window);
}

void Morning::update(const bool* keys, float dt) {

	test->update(dt);
}

void Morning::nextScene(SceneState& currentScene, keys* _myKeys) {

}
