#pragma once
#include "Scene.h"

class Morning : public Scene{
public:

	Morning(sf::RenderWindow& window);
	~Morning();

	void createGameObjects() ;
	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:
	Baker* test;
	Bakery* bakery;
	Store* store;
	CandyShop* candy_shop;
	Npc* npc;
	Npc* npc1;
	Npc* npc2;
};

