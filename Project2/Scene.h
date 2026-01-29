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


class Scene 
{
public:

	Scene();
	virtual ~Scene();
	virtual void displayScene(sf::RenderWindow& window) = 0; 
	virtual void nextScene(SceneState& currentScene, keys* _myKeys) = 0; 
};