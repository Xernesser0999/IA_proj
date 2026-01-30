#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "KeyStruct.h"

enum SceneState { // enum for state of scene
	menu,
	morning,
	day,
	night
};


class Scene // Inferface for different scene 
{
public:

	Scene();
	virtual ~Scene();
	virtual void displayScene(sf::RenderWindow& window); // Function for display scene
	virtual void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) = 0; // Function for change scene
};