#include "FluxNode.h"


// J'ai rien compris
FlowNode::FlowNode(FlowNode* ParentNode) : FlowNode(ParentNode, {}) {}
FlowNode::FlowNode(FlowNode* ParentNode, const std::vector<Node*>& Childs) : Node(ParentNode), ChildNodes(Childs) {
    CurrentExecuteChild = nullptr;
}

void FlowNode::AddChild(Node* Child) {
}

void FlowNode::RemoveChild(Node* Child) {
}

void FlowNode::OnChildWorkEnd(ENodeState ChildState) {
    auto It = std::find(ChildNodes.begin(), ChildNodes.end(), CurrentExecuteChild);
    if (It != ChildNodes.end()) {
        int Index = std::distance(ChildNodes.begin(), It) + 1;
        if (Index < ChildNodes.size()) {
            CurrentExecuteChild = ChildNodes[Index];
            CurrentExecuteChild->BeginExecute();
        }
        else {
            CurrentExecuteChild = nullptr;
        }
    }
}
