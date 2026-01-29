#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "KeyStruct.h"

enum SceneState { // enum for state of scene
	menu,
	play,
	quit,
	win
};


class Scene // Inferface for different scene 
{
public:

	Scene();
	virtual ~Scene();
	virtual void displayScene(sf::RenderWindow& window); // Function for display scene
	virtual void nextScene(SceneState& currentScene, keys* _myKeys) = 0; // Function for change scene
};