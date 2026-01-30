#include "Menu.h"
Menu::Menu(sf::RenderWindow& window) {
	createGameObjects();
}

Menu::~Menu() {

}

void Menu::createGameObjects() {
	button = new GUI_button(100, 100, 700, 100, "pp.png");
}

void Menu::displayScene(sf::RenderWindow& window) {
	button->render(window);
}

void Menu::update(const bool* keys, float dt, sf::RenderWindow& window) {
	button->hovered(window);
}

void Menu::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (button->clicked(window)) {
		currentScene = play;
	}
}