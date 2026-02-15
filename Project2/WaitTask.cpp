#include "WaitTask.h"
#include "Morning.h"


WaitTask::WaitTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void WaitTask::beginExecute() {
    startPoint = 0.0f; 
    timer = 2.0f;
    isActive = true;
}

void WaitTask::tick(float dt_) {
    if (!isActive) 
        return;  
    startPoint += dt_;

    if (startPoint >= timer) {
        endExecute();
    }
}

void WaitTask::endExecute() {
	isActive = false;
	getParent()->onChildWorkEnd(ENodeState::Success);
}

