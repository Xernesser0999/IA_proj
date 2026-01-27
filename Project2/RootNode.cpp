#include "RootNode.h"

RootNode::RootNode() = default;

RootNode::~RootNode(){
}

void RootNode::tick(float DeltaTime){
    if (childNode != nullptr)
    {
        childNode->tick(DeltaTime);
    }
}
