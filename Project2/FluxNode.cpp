#include "FluxNode.h"

FluxNode::FluxNode(FluxNode* parent, BehaviourTree* bt) : FluxNode(parent, {}, bt) {
}

FluxNode::FluxNode(FluxNode* parent, const std::vector<Node*>& children, BehaviourTree* bt)
	: Node(parent, bt), childNodes(children), currentExecuteChild(nullptr) {
}

void FluxNode::addChild(Node* child){
	childNodes.push_back(child);
}

void FluxNode::removeChild(Node* child){
	auto it = std::find(childNodes.begin(), childNodes.end(), child);
	if (it != childNodes.end()) {
		childNodes.erase(it);
	}
}

void FluxNode::beginExecute(){
	currentExecuteChild = *childNodes.begin();
	currentExecuteChild->beginExecute();
}

void FluxNode::tick(float dt){
	if (currentExecuteChild != nullptr)
	{
		currentExecuteChild->tick(dt);
	}

}

void FluxNode::onChildWorkEnd(ENodeState childState) {
	auto it = std::find(childNodes.begin(), childNodes.end(), currentExecuteChild);
	if (it != childNodes.end()) {
		int index = std::distance(childNodes.begin(), it) + 1;
		if (index < childNodes.size()) {
			currentExecuteChild = childNodes[index];
			currentExecuteChild->beginExecute();	
		}
		else {
			currentExecuteChild = nullptr;
		}
	}
}
