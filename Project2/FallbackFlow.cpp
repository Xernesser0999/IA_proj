#include "FallbackFlow.h"

FallbackFlow::FallbackFlow(FluxNode* parent) : FallbackFlow(parent, {}) {
}

FallbackFlow::FallbackFlow(FluxNode* parent, const std::vector<Node*>& children) : FluxNode(parent, children) {
}

void FallbackFlow::onChildWorkEnd(ENodeState childState) {
	if (childState == ENodeState::Failure) {
		FluxNode::onChildWorkEnd(childState);
		if (currentExecuteChild == nullptr) {
			getParent()->onChildWorkEnd(ENodeState::Success);
		}
	}
	else {
		FluxNode::onChildWorkEnd(ENodeState::Failure);
	}
}
