#include "DialogBox.h"

DialogBox::DialogBox() : text(font) {
}

DialogBox::DialogBox(float posX_, float posY_, float sizeX, float sizeY) : GameObjects(posX_, posY_, sizeX, sizeY), text(font) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/dialog_box.png");
	dialog = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
	dialog->setPosition(pos);
	dialog->setTexture(TX);

	font.openFromFile("Pixellettersfull-BnJ5.ttf");
	text.setFont(font);
	text.setString("Achat");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setPosition({ pos.x + size.x / 2, pos.y + size.y / 2 + 10});
}

void DialogBox::updateGameObject(float dt){
}

void DialogBox::renderGameObject(sf::RenderWindow& window){
	window.draw(*dialog);
	window.draw(text);
}
