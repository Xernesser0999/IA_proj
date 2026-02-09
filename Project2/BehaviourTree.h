#pragma once
#include <vector>
#include <chrono>


class Node;
class RootNode;
class Npc;

class Blackboard {};

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
	float coorNpcX;
	float coorNpcY;

	float shopCoorX;
	float shopCoorY;
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
