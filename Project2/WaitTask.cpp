#include "WaitTask.h"

WaitTask::WaitTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void WaitTask::beginExecute() {
	TaskNode::beginExecute();
	dt = clock.restart().asSeconds();

	startPoint = dt;
	timer = 5;

	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
}

void WaitTask::tick(float dt_) {
	TaskNode::tick(dt_);
	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
	
	actual = dt_;
	endExecute();
}

void WaitTask::endExecute() {
	if (actual - startPoint >= timer) {
		getParent()->onChildWorkEnd(ENodeState::Success);
	}
	else {
		getParent()->onChildWorkEnd(ENodeState::Failure);
	}
	return TaskNode::endExecute();
}
