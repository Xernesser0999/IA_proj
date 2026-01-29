#include "GUI_button.h"

GUI_button::GUI_button(float posX_, float posY_, std::string file) {

}

GUI_button::~GUI_button() {
	TX = nullptr;
	sprite = nullptr;

	delete TX;
	delete sprite;
}

bool GUI_button::hovered() {
	return true;
}

bool GUI_button::clicked() {
	return true;
}

void GUI_button::render(sf::RenderWindow& window) {
	window.draw(*sprite);
}