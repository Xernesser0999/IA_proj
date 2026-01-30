#pragma once
#include "Scene.h"

#include "Menu.h"

class SceneManager
{
public:

	SceneState currentState;

	Scene* myMenu;
	Scene* myPlay;

	SceneManager(sf::RenderWindow& window);
	~SceneManager();

	void manageState(keys* _myKeys, sf::RenderWindow& window);
	void displayState(sf::RenderWindow& window);
	void updateState(const bool* keys, float dt, sf::RenderWindow& window);
};