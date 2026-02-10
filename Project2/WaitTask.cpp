#include "WaitTask.h"
#include "Morning.h"


WaitTask::WaitTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void WaitTask::beginExecute() {
	auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
	dt = clock.restart().asSeconds();
	x = blackboard->coorNpcX;
	y = blackboard->coorNpcY;
	dial_ = new DialogBox(x+50, y+100, 30, 10);
	Morning::StaticDrawble.push_back(dial_);
	startPoint = 0;
	timer = 5;
	isActive = true;
}

void WaitTask::tick(float dt_) {
	startPoint += dt_;
	
	if (startPoint >= timer) {
		endExecute();
	}
}

void WaitTask::endExecute() {
	Morning::StaticDrawble.erase(std::find(Morning::StaticDrawble.begin(), Morning::StaticDrawble.end(), dial_));
	isActive = false;
	if (dial_) {
		delete dial_;
		dial_ = nullptr;
	}
	getParent()->onChildWorkEnd(ENodeState::Success);
	return TaskNode::endExecute();
}

