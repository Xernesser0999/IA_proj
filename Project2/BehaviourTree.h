#pragma once
#include <vector>
#include <chrono>


class Node;
class RootNode;
class Npc;

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

};

class NpcBehaviourTree : public BehaviourTree {
public:
	Blackboard* bt;
	NpcBehaviourTree();
	NpcBehaviourTree(Npc* npcOwner);
	virtual ~NpcBehaviourTree() override = default;

	virtual void buildTree() override;
	virtual void buildSubChilds() override;
};
