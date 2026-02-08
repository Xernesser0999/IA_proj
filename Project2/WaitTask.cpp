#include "WaitTask.h"

WaitTask::WaitTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void WaitTask::beginExecute(float dt) {
	TaskNode::beginExecute();

	startPoint = dt;
	timer = 5;

	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());

	x = blackboard->coorNpcX;
	y = blackboard->coorNpcY;

	speed = 300;

}

void WaitTask::tick(float dt) {
	TaskNode::tick(dt);
	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
	
	actual = dt;
	if (actual - startPoint >= timer) {
		endExecute();
	}
}

void WaitTask::endExecute() {
	if (actual - startPoint >= timer) {
		getParent()->onChildWorkEnd(ENodeState::Success);
	}
	return TaskNode::endExecute();
}
