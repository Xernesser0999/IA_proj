#include "SequenceFlow.h"

SequenceFlow::SequenceFlow(FluxNode* parent, BehaviourTree* bt) : SequenceFlow(parent, {}, bt) {
}

SequenceFlow::SequenceFlow(FluxNode* parent, const std::vector<Node*>& children, BehaviourTree* bt) : FluxNode(parent, children, bt) {
}

void SequenceFlow::onChildWorkEnd(ENodeState childState) {
    if (childState == ENodeState::Success) {
        FluxNode::onChildWorkEnd(childState);
        if (currentExecuteChild != nullptr) {
            currentExecuteChild->beginExecute();
        }
        else {
            if (getParent() != nullptr) {
                getParent()->onChildWorkEnd(ENodeState::Success);
            }
            else {
                currentExecuteChild = *childNodes.begin();
                currentExecuteChild->beginExecute();
            }
        }
    }
    else {
        if (getParent() != nullptr) {
            getParent()->onChildWorkEnd(ENodeState::Failure);
        }
        else {
            currentExecuteChild = *childNodes.begin();
            currentExecuteChild->beginExecute();
        }
    }
}

