#include "RootNode.h"

#include "FluxNode.h"

RootNode::RootNode(FluxNode* childNode, BehaviourTree* bt)
	: Node(nullptr, bt), child(childNode) {
}

void RootNode::beginExecute() {
	if (child != nullptr) {
		child->beginExecute();
	} 
}

void RootNode::tick(float dt) {
	child->tick(dt);
}

void RootNode::setChild(FluxNode* rootChild) {
	child = rootChild;
}