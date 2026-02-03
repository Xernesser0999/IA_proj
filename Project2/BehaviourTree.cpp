#include "BehaviourTree.h"

#include "RootNode.h"
#include "FallbackFlow.h"
#include "SequenceFlow.h"

BehaviourTree::BehaviourTree() : BehaviourTree(nullptr){
}

BehaviourTree::BehaviourTree(Npc* ownerNpc) : baseNode(nullptr), owner(ownerNpc), allNodes({}) {
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

void BehaviourTree::buildTree(){
	baseNode = new RootNode();
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

void NpcBehaviourTree::buildSubChilds(){
	FallbackFlow* FallBack = new FallbackFlow();
	baseNode->setChild(FallBack);

	SequenceFlow* Sequence = new SequenceFlow(FallBack);
	FallBack->addChild(Sequence);
}
