#include "SequenceFlow.h"

SequenceFlow::SequenceFlow(FluxNode* parent) : SequenceFlow(parent, {}) {
}

SequenceFlow::SequenceFlow(FluxNode* parent, const std::vector<Node*>& children) : FluxNode(parent, children) {
}

void SequenceFlow::onChildWorkEnd(ENodeState childState) {
	if (childState == ENodeState::Success) {
		FluxNode::onChildWorkEnd(childState);
		if(currentExecuteChild == nullptr) {
			getParent()->onChildWorkEnd(ENodeState::Success);
		}
		else {
			getParent()->onChildWorkEnd(ENodeState::Failure);
		}
	}

}
