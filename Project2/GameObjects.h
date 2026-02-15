#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include "BehaviourTree.h"

#include <string>
class GameObjects{
public:
	GameObjects();
	GameObjects(float posX_, float posY_, float sizeX, float sizeY);
	virtual ~GameObjects();

	virtual void renderGameObject(sf::RenderWindow& window);
	virtual void updateGameObject(float dt); 
	void requestItem();
	ShopBlackBoard* getShopBlackboard() const { return shopBb; }
	void initShopTree(int startingStock);

public:
	bool hover;
	sf::Vector2f pos;
	sf::Vector2f size;

	sf::Texture* TX;
	sf::Texture* TX2;

	sf::RectangleShape* shop;
	ShopTree* shopTree = nullptr;
	ShopBlackBoard* shopBb = nullptr;
};

