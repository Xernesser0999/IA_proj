#include "SequenceFlow.h"

SequenceFlow::SequenceFlow(FluxNode* parent, BehaviourTree* bt) : SequenceFlow(parent, {}, bt) {
}

SequenceFlow::SequenceFlow(FluxNode* parent, const std::vector<Node*>& children, BehaviourTree* bt) : FluxNode(parent, children, bt) {
}

void SequenceFlow::onChildWorkEnd(ENodeState childState) {
	if (childState == ENodeState::Success) {
		FluxNode::onChildWorkEnd(childState);
		if(currentExecuteChild == nullptr) {
			getParent()->onChildWorkEnd(ENodeState::Success);
		}
	}
	else {
		FluxNode::onChildWorkEnd(ENodeState::Failure);
	}
}
