#include "WaitForNpcTask.h"

WaitForNpcTask::WaitForNpcTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void WaitForNpcTask::beginExecute() {
	isActive = true;
}

void WaitForNpcTask::tick(float dt) {
	if (!isActive)
		return;
	endExecute();
}


void WaitForNpcTask::endExecute() {
	auto blackboard = static_cast<ShopBlackBoard*>(getBehaviourTree()->getBlackboard());
	if (blackboard->npcRequest) {
		getParent()->onChildWorkEnd(ENodeState::Success);
	}
	else {
		getParent()->onChildWorkEnd(ENodeState::Failure);
	}
}
