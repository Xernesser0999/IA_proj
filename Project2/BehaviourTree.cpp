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
#include "CheckStockTask.h"
#include "WaitForNpcTask.h"

BehaviourTree::BehaviourTree() : BehaviourTree(nullptr){
}

BehaviourTree::BehaviourTree(Npc* ownerNpc) : baseNode(nullptr), owner(ownerNpc), allNodes({}), blackboard(nullptr) {
	buildTree();
}

BehaviourTree::BehaviourTree(bool)
	: baseNode(nullptr), owner(nullptr), allNodes({}), blackboard(nullptr) {
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

StoreTree::StoreTree() : BehaviourTree(false), storeOwner(nullptr) {
}

StoreTree::StoreTree(GameObjects* ownerObj) : BehaviourTree(false), storeOwner(ownerObj) {
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

	// --- Happy path: stock available ---
	// MoveTo ? Request ? Wait ? QuitWalk ? Stop
	SequenceFlow* Sequence = new SequenceFlow(FallBack, this);
	FallBack->addChild(Sequence);

	MoveToTask* moveTo = new MoveToTask(Sequence, this);
	RequestTask* request = new RequestTask(Sequence, this);
	WaitTask* wait = new WaitTask(Sequence, this);
	AIQuitTask* quit = new AIQuitTask(Sequence, this);
	AiStop* stop = new AiStop(Sequence, this);  // FIX: parent is Sequence
	Sequence->addChild(moveTo);
	Sequence->addChild(request);
	Sequence->addChild(wait);
	Sequence->addChild(quit);
	Sequence->addChild(stop);  

	SequenceFlow* SequenceQuit = new SequenceFlow(FallBack, this);
	FallBack->addChild(SequenceQuit);

	AngryQuit* angry = new AngryQuit(SequenceQuit, this);
	AIQuitTask* quitAngry = new AIQuitTask(SequenceQuit, this);
	AiStop* stopAngry = new AiStop(SequenceQuit, this); 
	SequenceQuit->addChild(angry);
	SequenceQuit->addChild(quitAngry);
	SequenceQuit->addChild(stopAngry); 

	allNodes.push_back(FallBack);
	allNodes.push_back(Sequence);
	allNodes.push_back(moveTo);
	allNodes.push_back(request);
	allNodes.push_back(wait);
	allNodes.push_back(quit);
	allNodes.push_back(stop);
	allNodes.push_back(SequenceQuit);
	allNodes.push_back(angry);
	allNodes.push_back(quitAngry);
	allNodes.push_back(stopAngry);
}

// Store Behavior tree
ShopTree::ShopTree(GameObjects* owner) : StoreTree(owner){
}

void ShopTree::buildTree() {
	baseNode = new RootNode();
	buildSubChilds();
}

void ShopTree::buildSubChilds() {
	FallbackFlow* fallback = new FallbackFlow(nullptr, this);
	baseNode->setChild(fallback);

	SequenceFlow* sequence = new SequenceFlow(fallback, this);
	fallback->addChild(sequence);

	WaitForNpcTask* waitForCustomer = new WaitForNpcTask(sequence, this);
	sequence->addChild(waitForCustomer);
	CheckStockTask* checkStock = new CheckStockTask(sequence, this);
	sequence->addChild(checkStock);

	allNodes.push_back(fallback);
	allNodes.push_back(sequence);
	allNodes.push_back(waitForCustomer);
	allNodes.push_back(checkStock);
}


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
