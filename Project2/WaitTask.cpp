#include "WaitTask.h"

WaitTask::WaitTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void WaitTask::beginExecute() {
	TaskNode::beginExecute();
	dt = clock.restart().asSeconds();

	startPoint = 0;
	timer = 5;

	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
}

void WaitTask::tick(float dt_) {
	TaskNode::tick(dt_);
	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
	
	startPoint += dt_;

	if (startPoint >= timer) {
		endExecute();
	}
}

void WaitTask::endExecute() {
	getParent()->onChildWorkEnd(ENodeState::Success);
	return TaskNode::endExecute();
}
