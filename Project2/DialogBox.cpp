#include "DialogBox.h"

DialogBox::DialogBox(){
}

DialogBox::DialogBox(float posX_, float posY_, float sizeX, float sizeY) : GameObjects(posX_, posY_, sizeX, sizeY) {
	TX = new sf::Texture();
	TX->loadFromFile("sprite/dialog_box.png");
	dialog = new sf::RectangleShape();
	dialog->setTexture(TX);
}

void DialogBox::updateGameObject(float dt){
}

void DialogBox::renderGameObject(sf::RenderWindow& window){
	window.draw(*dialog);
}
