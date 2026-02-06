#include "Node.h"

#include "FluxNode.h"

Node::Node(FluxNode* parent, BehaviourTree* bt) : parent(parent, bt){
}

void Node::beginExecute(){
}

void Node::tick(float dt){
}

void Node::endExecute(){
}

void Node::abort(){
}

FluxNode* Node::getParent() const{
	return parent;
}

BehaviourTree* Node::getBehaviourTree() const
{
	return behaviourTree;
}

