#include "FluxNode.h"

FluxNode::FluxNode(FluxNode* parent) : FluxNode(parent, {}) {
}

FluxNode::FluxNode(FluxNode* parent, const std::vector<Node*>& children)
	: Node(parent), childNodes(children), currentExecuteChild(nullptr) {
}

void FluxNode::addChild(Node* child){
}

void FluxNode::removeChild(Node* child){
}

void FluxNode::beginExecute(){
	currentExecuteChild = *childNodes.begin();
	currentExecuteChild->beginExecute();
}

void FluxNode::tick(float dt){
	currentExecuteChild->tick(dt);
}

void FluxNode::onChildWorkEnd(ENodeState childState){
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
