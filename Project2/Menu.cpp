#include "Menu.h"
Menu::Menu(sf::RenderWindow& window) {
	createGameObjects();
}

Menu::~Menu() {

}

void Menu::createGameObjects() {
	button = new GUI_button(1920/2-250, 1080/2-50, 500, 100, "sprite/Play_button.png", "sprite/Play_button_hover.png");
	Quit_button = new GUI_button(1920 / 2 - 250, 1080 / 2 - 50 + 100, 500, 100, "sprite/quit.png", "sprite/quit_hover.png");
}

void Menu::displayScene(sf::RenderWindow& window) {
	button->render(window);
	Quit_button->render(window);
}

void Menu::update(const bool* keys, float dt, sf::RenderWindow& window) {
	button->hovered(window);
	Quit_button->hovered(window);
}

void Menu::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (button->clicked(window)) {
		currentScene = morning;
	}
	if (Quit_button->clicked(window)) {
		exit(0);
	}
}