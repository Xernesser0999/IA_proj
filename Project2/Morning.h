#pragma once
#include "Scene.h"
#include "BehaviourTree.h"

class Morning : public Scene{
public:

	Morning(sf::RenderWindow& window);
	~Morning();

	void createGameObjects() ;
	void displayScene(sf::RenderWindow& window) override;
	void setImages(sf::RectangleShape* myRect, const char* path, float x, float y, float w, float h);
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;
	void spawnNpc();

public:
	Baker* test;
	Bakery* bakery;
	Store* store;
	CandyShop* candy_shop;
	std::vector<GameObjects*> shops;
	std::vector<Npc*> npcs;
	std::vector<NpcBehaviourTree*> npcBehaviorTrees;
	std::vector<NpcBlackBoard*> npcBlackboards;
	Clock btClock;
	Clock spawnClock;
	float spawnTimer;
	const float spawnInterval = 2.0f; 
	std::vector<sf::Texture*> vecTex;
	sf::RectangleShape* bg;
	const float duration = 20.0f;

	static std::vector<GameObjects*> StaticDrawble;
};

