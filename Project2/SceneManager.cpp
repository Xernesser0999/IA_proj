#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window) {
	
	currentState = SceneState::menu;
	previousState = SceneState::morning;

	myMenu = new Menu(window);
	myMorning = new Morning(window);
	myDay = new Day(window);
	myNight = new Night(window);
}

SceneManager::~SceneManager() {


	delete myMorning;
	myMorning = nullptr;
	delete myMenu;
	myMenu = nullptr;
	delete myDay;
	myDay = nullptr;
	delete myNight;
	myNight = nullptr;
}

void SceneManager::manageState(keys* _myKeys, sf::RenderWindow& window) {
	if (currentState == SceneState::menu) {
		myMenu->nextScene(currentState, _myKeys, window);
	}
	else if (currentState == SceneState::morning) {
		myMorning->nextScene(currentState, _myKeys, window);
	}
	else if (currentState == SceneState::day) {
		myDay->nextScene(currentState, _myKeys, window);
	}
	else if (currentState == SceneState::night) {
		myNight->nextScene(currentState, _myKeys, window);
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
	case SceneState::day:
		myDay->displayScene(window);
		break;
	case SceneState::night:
		myNight->displayScene(window);
		break;
	}
}

void SceneManager::updateState(const bool* keys, float dt, sf::RenderWindow& window) {
	if (currentState == SceneState::morning) {
		static_cast<Morning*>(myMorning)->update(keys, dt);
	}
	else if (currentState == SceneState::menu) {
		static_cast<Menu*>(myMenu)->update(keys, dt, window);
	}
	else if (currentState == SceneState::night) {
		static_cast<Night*>(myNight)->update(keys, dt);
	}
	else if (currentState == SceneState::day) {
		static_cast<Day*>(myDay)->update(keys, dt);
	}
}