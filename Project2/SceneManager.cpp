#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window) {
	currentState = SceneState::menu;

	//myMenu = new Menu(renderer, window);
	//myPlay = new Play(renderer, window);
	//myWin = new Win(renderer, window);
}

SceneManager::~SceneManager() {


	delete myPlay;
	myPlay = nullptr;
	delete myMenu;
	myMenu = nullptr;
}

void SceneManager::manageState(keys* _myKeys) {
	if (currentState == SceneState::play) {
		myPlay->nextScene(currentState, _myKeys);
	}
	else if (currentState == SceneState::menu) {
		myMenu->nextScene(currentState, _myKeys);
	}
}

void SceneManager::displayState(sf::RenderWindow& window) {
	//switch (currentState)
	//{
	//case SceneState::play:
	//	myPlay->displayScene(window);
	//	break;
	//case SceneState::menu:
	//	myMenu->displayScene(window);
	//	break;
	//case SceneState::win:
	//	myWin->displayScene(window);
	//	break;
	//}
}

void SceneManager::updateState(const bool* keys, float dt) {
	//if (currentState == SceneState::play) {
	//	static_cast<Play*>(myPlay)->update(keys, dt);
	//}
	//else if (currentState == SceneState::menu) {
	//	static_cast<Menu*>(myMenu)->update(keys, dt);
	//}
	//else if (currentState == SceneState::win) {
	//	static_cast<Win*>(myWin)->update(keys, dt);
	//}
}