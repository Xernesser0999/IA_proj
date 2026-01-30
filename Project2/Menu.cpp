#include "Menu.h"
Menu::Menu(sf::RenderWindow& window) {
	createGameObjects();
}

Menu::~Menu() {

}


void Menu::createGameObjects()  {
	test1 = new Baker(500, 0, "pp.png");
}

void Menu::displayScene(sf::RenderWindow& window){
	test1->render(window);
}

void Menu::update(const bool* keys, float dt) {
	test1->update(dt);
}

void Menu::nextScene(SceneState& currentScene, keys* _myKeys) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::E)) {
		currentScene = SceneState::morning;
	}
}