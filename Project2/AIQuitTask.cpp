#include "AIQuitTask.h"

AIQuitTask::AIQuitTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void AIQuitTask::beginExecute() {
	TaskNode::beginExecute();

	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
	targetX = 1960;
	targetY = 1080/2;

	x = blackboard->coorNpcX;
	y = blackboard->coorNpcY;

	speed = 250;
}

void AIQuitTask::tick(float dt) {
	TaskNode::tick(dt);

	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());

	if (y < targetY) {
		y += speed * dt;
		if (y > targetY) y = targetY;
	}
	else if (y > targetY) {
		y -= speed * dt;
		if (y < targetY) y = targetY;
	}
	else if (x < targetX) {
		x += speed * dt;
		if (x > targetX) x = targetX;
	}
	else if (x > targetX) {
		x -= speed * dt;
		if (x < targetX) x = targetX;
	}

	blackboard->coorNpcX = x;
	blackboard->coorNpcY = y;

	if (x == targetX && y == targetY) {
		endExecute();
	}
}

void AIQuitTask::endExecute() {
	if (targetX == x && targetY == y) {
		getParent()->onChildWorkEnd(ENodeState::Success);
	}
	return TaskNode::endExecute();
}
