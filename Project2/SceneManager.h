#pragma once
#include "Scene.h"
#include "Menu.h"
#include "Morning.h"
#include "Day.h"
#include "Night.h"

#include "Menu.h"

class SceneManager{
public:

	SceneState currentState;
	SceneState previousState;

	Scene* myMenu;
	Scene* myMorning;
	Scene* myDay;
	Scene* myNight;

	SceneManager(sf::RenderWindow& window);
	~SceneManager();

	void manageState(keys* _myKeys, sf::RenderWindow& window);
	void displayState(sf::RenderWindow& window);
	void updateState(const bool* keys, float dt, sf::RenderWindow& window);
};