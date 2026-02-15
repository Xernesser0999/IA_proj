#include "MoveToTask.h"

MoveToTask::MoveToTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt){
}

void MoveToTask::beginExecute() {

	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
	targetX = blackboard->shopCoorX;
	targetY = blackboard->shopCoorY;

	x = blackboard->coorNpcX;
	y = blackboard->coorNpcY;

	speed = 250;

}

void MoveToTask::tick(float dt){

	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());

	if (x < targetX) {
		x += speed * dt;
		if (x > targetX) x = targetX;
	}
	else if (x > targetX) {
		x -= speed * dt;
		if (x < targetX) x = targetX;
	}
	
	else if (y < targetY) {
		y += speed * dt;
		if (y > targetY) y = targetY;
	}
	else if (y > targetY) {
		y -= speed * dt;
		if (y < targetY) y = targetY;
	}

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
}
