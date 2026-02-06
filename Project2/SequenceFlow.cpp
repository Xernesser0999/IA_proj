#include "SequenceFlow.h"

SequenceFlow::SequenceFlow(FlowNode* ParentNode) : SequenceFlow(ParentNode, {}) {
}

SequenceFlow::SequenceFlow(FlowNode* ParentNode, const std::vector<Node*>& Childs) : FlowNode(ParentNode, Childs) {

}

void SequenceFlow::OnChildWorkEnd(ENodeState ChildState) {
    if (ChildState == ENodeState::Success) {
        FlowNode::OnChildWorkEnd(ChildState);
        if (CurrentExecuteChild == nullptr) {//No more node to play
            GetParent()->OnChildWorkEnd(ENodeState::Success);
        }
    }
    else {
        GetParent()->OnChildWorkEnd(ENodeState::Failure);
    }
}
