#include "MoveToTask.h"

MoveToTask::MoveToTask(FluxNode* parent) : TaskNode(parent){
}

void MoveToTask::beginExecute() {
	TaskNode::beginExecute();

	auto blackboard = static_cast<NpcBlackBoard*>(BehaviourTree::blackBoard);
	targetX = blackboard->shopCoorX;
	targetY = blackboard->shopCoorY;

	x = blackboard->coorNpcX;
	y = blackboard->coorNpcY;

	speed = 300;
}

void MoveToTask::tick(float dt){
	TaskNode::tick(dt);

	auto blackboard = static_cast<NpcBlackBoard*>(BehaviourTree::blackBoard);

	float fx = static_cast<float>(x);
	float fy = static_cast<float>(y);
	const float ftargX = static_cast<float>(targetX);
	const float ftargY = static_cast<float>(targetY);

	if (fx < ftargX) {
		fx += speed * dt;
		if (fx > ftargX) fx = ftargX;
	}
	else if (fx > ftargX) {
		fx -= speed * dt;
		if (fx < ftargX) fx = ftargX;
	}

	if (fy < ftargY) {
		fy += speed * dt;
		if (fy > ftargY) fy = ftargY;
	}
	else if (fy > ftargY) {
		fy -= speed * dt;
		if (fy < ftargY) fy = ftargY;
	}

	x = static_cast<int>(fx);
	y = static_cast<int>(fy);
	blackboard->coorNpcX = x;
	blackboard->coorNpcY = y;

	if (x == targetX && y == targetY) {
		endExecute();
	}
}

void MoveToTask::endExecute(){
	if (targetX == x && targetY == y) {
		getParent()->onChildWorkEnd(ENodeState::Success);
	}
	return TaskNode::endExecute();
}
