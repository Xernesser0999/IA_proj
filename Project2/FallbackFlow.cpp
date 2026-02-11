#include "FallbackFlow.h"

FallbackFlow::FallbackFlow(FluxNode* parent, BehaviourTree* bt) : FallbackFlow(parent, {}, bt) {
}

FallbackFlow::FallbackFlow(FluxNode* parent, const std::vector<Node*>& children, BehaviourTree* bt) : FluxNode(parent, children, bt) {
}

void FallbackFlow::onChildWorkEnd(ENodeState childState) {
	if (childState == ENodeState::Failure) {
		FluxNode::onChildWorkEnd(childState);
		if (currentExecuteChild == nullptr) {
			getParent()->onChildWorkEnd(ENodeState::Failure);	
		}
	}
	else {
		FluxNode::onChildWorkEnd(ENodeState::Success);
	}
}
