#include "FallbackFlow.h"

FallbackFlow::FallbackFlow(FlowNode* ParentNode) : FallbackFlow(ParentNode, {}) {
}

FallbackFlow::FallbackFlow(FlowNode* ParentNode, const std::vector<Node*>& Childs) : FlowNode(ParentNode, Childs) {
}

void FallbackFlow::OnChildWorkEnd(ENodeState ChildState) {
    if (ChildState == ENodeState::Failure) {
        FlowNode::OnChildWorkEnd(ChildState);
        if (CurrentExecuteChild == nullptr) {//No more node to play
            GetParent()->OnChildWorkEnd(ENodeState::Success);
        }
    }
    else {
        GetParent()->OnChildWorkEnd(ENodeState::Failure);
    }
}
