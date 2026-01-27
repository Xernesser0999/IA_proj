#include "FluxNode.h"

FluxNode::FluxNode(){
}

FluxNode::~FluxNode(){
}

void FluxNode::tick(float DeltaTime){
    if (actualNode == nullptr) {
        actualNode = childNodes.front();
        actualNode->begin();
    }
    actualNode->tick(DeltaTime);
}

void FluxNode::onNodeEnd(){
    auto It = std::find(childNodes.begin(), childNodes.end(), actualNode);
    if (It != childNodes.end()) {
        int Index = std::distance(childNodes.begin(), It);
        if (Index < childNodes.size() - 1) {
            Index++;
        }
        else {
            Index = 0;
        }
        actualNode = childNodes[Index];
        actualNode->begin();
    }
}
