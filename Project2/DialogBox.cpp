#include "DialogBox.h"

DialogBox::DialogBox() : textdial(font) {
}

DialogBox::DialogBox(float posX_, float posY_, float sizeX, float sizeY) : GameObjects(posX_, posY_, sizeX, sizeY), textdial(font) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/dialog_box.png");
	dialog = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
	dialog->setPosition(pos);
	dialog->setTexture(TX);

	font.openFromFile("Pixellettersfull-BnJ5.ttf");
	textdial.setFont(font);
	textdial.setString("Achat");
	textdial.setCharacterSize(24);
	textdial.setFillColor(sf::Color::Black);
	textdial.setPosition({ pos.x + size.x / 2, pos.y + size.y / 2 + 10});
}

void DialogBox::updateGameObject(float dt){
}

void DialogBox::renderGameObject(sf::RenderWindow& window){
	window.draw(*dialog);
	window.draw(textdial);
}

void DialogBox::text(std::string text_) {
	textdial.setString(text_);
}