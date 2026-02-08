#include "BehaviourTree.h"

#include "RootNode.h"
#include "FallbackFlow.h"
#include "SequenceFlow.h"
#include "MoveToTask.h"

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
	Sequence->addChild(moveTo);

	allNodes.push_back(FallBack);
	allNodes.push_back(Sequence);
	allNodes.push_back(moveTo);

}

Clock::Clock(bool startNow){
	if (startNow) {
		start();
	}
}

void Clock::start(){
	restart();
}

float Clock::restart(){
	std::chrono::time_point<std::chrono::steady_clock> actual = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = actual - timeStart;

	timeStart = actual;
	lastCallElpased = actual;

	return duration.count();
}

float Clock::getElapsedTime(){
	std::chrono::time_point<std::chrono::steady_clock> actual = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = actual - lastCallElpased;

	lastCallElpased = actual;
	return duration.count();
}

float Clock::timeSinceStart(){
	std::chrono::time_point<std::chrono::steady_clock> actual = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = actual - timeStart;
	return duration.count();
}
