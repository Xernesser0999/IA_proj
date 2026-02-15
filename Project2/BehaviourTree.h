#pragma once
#include <vector>
#include <chrono>


class Node;
class RootNode;
class Npc;
class GameObjects;

class Blackboard {};

class Clock {
public: 
	Clock() = default;
	Clock(bool startNow);

	void start();
	float restart();
	float getElapsedTime();
	float timeSinceStart();

private:
	std::chrono::time_point<std::chrono::steady_clock> timeStart;
	std::chrono::time_point<std::chrono::steady_clock> lastCallElpased;
};

class BehaviourTree{
public:
	BehaviourTree();
	BehaviourTree(Npc* ownerNpc);
	virtual ~BehaviourTree();

	void execute();
	void tick(float dt);
	void abort();

	Blackboard* getBlackboard() const;
	void setBlackboard(Blackboard* bb);

	virtual void buildTree();
	virtual void buildSubChilds();
	void cleanTree();
	BehaviourTree(bool); //pas trouvé de solutions, aide ia

protected:
	RootNode* baseNode;
	Npc* owner;
	std::vector<Node*> allNodes;
	Blackboard* blackboard;
};

class NpcBlackBoard : public Blackboard {
public:
	int coorNpcX;
	int coorNpcY;

	int shopCoorX;
	int shopCoorY;
	GameObjects* targetShop = nullptr;

};

class ShopBlackBoard : public Blackboard {
public:
	int  stock = 10;   
	bool npcRequest = false; 
	bool sale = false; 
	bool result = false;
};

class NpcBehaviourTree : public BehaviourTree {
public:
	NpcBehaviourTree();
	NpcBehaviourTree(Npc* npcOwner);
	virtual ~NpcBehaviourTree() override = default;

	virtual void buildTree() override;
	virtual void buildSubChilds() override;
public:
	Blackboard* bt;
};

class StoreTree : public BehaviourTree {
public:
	StoreTree();
	StoreTree(GameObjects* storeOwner);
	virtual ~StoreTree() override = default;

protected:
	GameObjects* storeOwner;  
};

class ShopTree : public StoreTree {
public:
	ShopTree() = default;
	ShopTree(GameObjects* owner);
	virtual ~ShopTree() override = default;

	virtual void buildTree() override;
	virtual void buildSubChilds() override;
public:
	Blackboard* bt;
};