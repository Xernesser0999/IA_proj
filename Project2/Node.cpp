#include "Node.h"

#include "FluxNode.h"

Node::Node(FluxNode* parent) : parent(parent){
}

void Node::beginExecute(){
}

void Node::endExecute(){
}

void Node::abort(){
}

FluxNode* Node::getParent() const{
	return parent;
}

