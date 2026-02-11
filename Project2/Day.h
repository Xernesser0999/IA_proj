#pragma once
#include "Scene.h"
#include "BehaviourTree.h"

class Day : public Scene {
public:

	Day(sf::RenderWindow& window);
	~Day();

	void createGameObjects();
	void displayScene(sf::RenderWindow& window) override;
	void setImages(sf::RectangleShape* myRect, const char* path, float x, float y, float w, float h);
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;
	void spawnNpc();

	void clearlevel();

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
	sf::Vector2f pos = { 1920 - 320, 0 };
	sf::Vector2f size = { 320, 320 };

	sf::Texture* TX;
	sf::RectangleShape* rectangle;

	float timer;
	float startPoint;

	bool daypass;
	int Day_number = 1;

	sf::Font fonta;
	sf::Text textclock;

	static std::vector<GameObjects*> StaticDrawble;
};
