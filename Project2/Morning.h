#pragma once
#include "Scene.h"
#include "BehaviourTree.h"
#include <iostream>
#include <vector>

class Morning : public Scene{
public:

	Morning(sf::RenderWindow& window);
	~Morning();

	void createGameObjects() ;
	void displayScene(sf::RenderWindow& window) override;
	void update(float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:
	Baker* test;
	Bakery* bakery;
	Store* store;
	CandyShop* candy_shop;
	std::vector<Npc*> npcVec;
	std::vector<Shop*> shopVec;

	Npc* npc;
	BehaviourTree* npcBt;
	sf::Clock btClock;
	sf::Clock spawn;
	float clockSpawn;
	NpcBlackBoard* npcBlackboard;

	const float duration = 20.0f;
};

