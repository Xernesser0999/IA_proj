#include "BehaviourTree.h"

#include "RootNode.h"
#include "FallbackFlow.h"
#include "SequenceFlow.h"
#include "MoveToTask.h"
#include "WaitTask.h"
#include "AIQuitTask.h"
#include "RequestTask.h"
#include "AngryQuitTask.h"
#include "AiStop.h"

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

StoreTree::StoreTree() {
}

StoreTree::StoreTree(GameObjects* owner) : baseNode(nullptr), owner(owner), allNodes({}), blackboard(nullptr) {
	buildTree();
}

StoreTree::~StoreTree() {
	cleanTree();
}

void StoreTree::execute() {
	baseNode->beginExecute();
}

void StoreTree::tick(float dt) {
	baseNode->tick(dt);
}

void StoreTree::abort() {
	baseNode->abort();
}

Blackboard* StoreTree::getBlackboard() const {
	return blackboard;
}

void StoreTree::setBlackboard(Blackboard* bb) {
	blackboard = bb;
}

void StoreTree::buildTree() {
	baseNode = new RootNode;
	buildSubChilds();
}

void StoreTree::cleanTree() {
	delete baseNode;
	baseNode = nullptr;
	for (auto* node : allNodes) {
		delete node;
		node = nullptr;
	}
	allNodes.clear();
}

void StoreTree::buildSubChilds() {
}

// NPC behavior tree
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
	RequestTask* request = new RequestTask(Sequence, this);
	WaitTask* wait = new WaitTask(Sequence, this);
	AIQuitTask* quit = new AIQuitTask(Sequence, this);
	AiStop* stop = new AiStop(Sequence, this);
	Sequence->addChild(moveTo);
	Sequence->addChild(request);
	Sequence->addChild(wait);
	Sequence->addChild(quit);

	SequenceFlow* SequenceQuit = new SequenceFlow(FallBack, this);
	FallBack->addChild(SequenceQuit);

	AngryQuit* angry = new AngryQuit(SequenceQuit, this);
	SequenceQuit->addChild(angry);
	AIQuitTask* quitAngry = new AIQuitTask(SequenceQuit, this);
	SequenceQuit->addChild(quitAngry);
	SequenceQuit->addChild(stop);

	allNodes.push_back(FallBack);
	allNodes.push_back(angry);
	allNodes.push_back(quitAngry);
	allNodes.push_back(Sequence);
	allNodes.push_back(moveTo);
	allNodes.push_back(request);
	allNodes.push_back(wait);
	allNodes.push_back(quit);
	allNodes.push_back(stop);
	allNodes.push_back(SequenceQuit);
}

// Store Behavior tree


// Clock
Clock::Clock(bool startNow) {
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
