#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window) {
	
	currentState = SceneState::morning;
	previousState = SceneState::morning;;

	myMenu = new Menu(window);
	myMorning = new Morning(window);
}

SceneManager::~SceneManager() {


	delete myMorning;
	myMorning = nullptr;
	delete myMenu;
	myMenu = nullptr;
}

void SceneManager::manageState(keys* _myKeys) {
	if (currentState == SceneState::morning) {
		myMorning->nextScene(currentState, _myKeys);
	}
	else if (currentState == SceneState::menu) {
		myMenu->nextScene(currentState, _myKeys);
	}
}

void SceneManager::displayState(sf::RenderWindow& window) {
	switch (currentState)
	{
	case SceneState::morning:
		myMorning->displayScene(window);
		break;
	case SceneState::menu:
		myMenu->displayScene(window);
		break;
	}
}

void SceneManager::updateState(const bool* keys, float dt) {
	if (currentState == SceneState::morning) {
		static_cast<Morning*>(myMorning)->update(keys, dt);
	}
	else if (currentState == SceneState::menu) {
		static_cast<Menu*>(myMenu)->update(keys, dt);
	}
}