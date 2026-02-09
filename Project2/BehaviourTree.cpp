#include "BehaviourTree.h"

#include "RootNode.h"
#include "FallbackFlow.h"
#include "SequenceFlow.h"
#include "MoveToTask.h"
#include "WaitTask.h"
#include "AIQuitTask.h"

BehaviourTree::BehaviourTree() : BehaviourTree(nullptr){
}

BehaviourTree::BehaviourTree(Npc* ownerNpc) : baseNode(nullptr), owner(ownerNpc), allNodes({}), blackboard(nullptr) {
	buildTree();
}

BehaviourTree::~BehaviourTree(){
	cleanTree();
}

void BehaviourTree::execute(){
	baseNode->beginExecute();
}

void BehaviourTree::tick(float dt){
	baseNode->tick(dt);
}

void BehaviourTree::abort(){
	baseNode->abort();
}

Blackboard* BehaviourTree::getBlackboard() const{
	return blackboard;
}

void BehaviourTree::setBlackboard(Blackboard* bb){
	blackboard = bb;
}

void BehaviourTree::buildTree(){
	baseNode = new RootNode(nullptr, this);
	buildSubChilds();
}

void BehaviourTree::cleanTree() {
	delete baseNode;
	baseNode = nullptr;
	for (auto* node : allNodes) {
		delete node;
		node = nullptr;
	}
	allNodes.clear();
}

void BehaviourTree::buildSubChilds(){
}

NpcBehaviourTree::NpcBehaviourTree() : NpcBehaviourTree(nullptr){
}

NpcBehaviourTree::NpcBehaviourTree(Npc* npcOwner) : BehaviourTree(npcOwner) {

}

void NpcBehaviourTree::buildTree(){
	baseNode = new RootNode();
	buildSubChilds();
}

void NpcBehaviourTree::buildSubChilds(){
	FallbackFlow* FallBack = new FallbackFlow(nullptr, this);
	baseNode->setChild(FallBack);

	SequenceFlow* Sequence = new SequenceFlow(FallBack, this);
	FallBack->addChild(Sequence);

	MoveToTask* moveTo = new MoveToTask(Sequence, this);
	WaitTask* wait = new WaitTask(Sequence, this);
	AIQuitTask* quit = new AIQuitTask(Sequence, this);
	Sequence->addChild(moveTo);
	Sequence->addChild(wait);
	Sequence->addChild(quit);

	allNodes.push_back(FallBack);
	allNodes.push_back(Sequence);

	allNodes.push_back(moveTo);
	allNodes.push_back(wait);
	allNodes.push_back(quit);
}
