#pragma once
#include <vector>


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
	static Blackboard* blackBoard;

protected:
	void buildTree();
	virtual void buildSubChilds();
	void cleanTree();

protected:
	RootNode* baseNode;
	Npc* owner;
	std::vector<Node*> allNodes;
};

class NpcBlackBoard : public Blackboard {
public:
	int coorNpcX;
	int coorNpcY;
};

class NpcBehaviourTree : public BehaviourTree {
public:
	NpcBehaviourTree();
	NpcBehaviourTree(Npc* npcOwner);
	virtual ~NpcBehaviourTree() override = default;

	virtual void buildSubChilds() override;
};
