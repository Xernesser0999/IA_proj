#include "RootNode.h"
#include "FluxNode.h"

RootNode::RootNode(FlowNode* ChilNode) : Node(nullptr), Child(ChilNode) {
}

void RootNode::BeginExecute() {
    if (Child != nullptr) {
        Child->BeginExecute();
    }
}

void RootNode::SetChild(FlowNode* RootChild) {
    Child = RootChild;
}
