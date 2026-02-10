#include "RequestTask.h"

#include "Morning.h"


RequestTask::RequestTask(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

void RequestTask::beginExecute() {
    auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
    x = blackboard->coorNpcX;
    y = blackboard->coorNpcY;
    dial_ = new DialogBox(x - 50, y - 80, 150, 45);
    Morning::StaticDrawble.push_back(dial_);

    startPoint = 0.0f;
    timer = 2.0f;
    isActive = true;
}

void RequestTask::tick(float dt_) {
    if (!isActive)
        return;

    auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
    if (dial_ && dial_->dialog) {
        x = blackboard->coorNpcX - 25;
        y = blackboard->coorNpcY - 50;
        dial_->dialog->setPosition(sf::Vector2f(x, y));
    }
    startPoint += dt_;

    if (startPoint >= timer) {
        endExecute();
    }
}

void RequestTask::endExecute() {
    Morning::StaticDrawble.erase(std::find(Morning::StaticDrawble.begin(), Morning::StaticDrawble.end(), dial_));
    isActive = false;
    if (dial_) {
        delete dial_;
        dial_ = nullptr;
    }
    getParent()->onChildWorkEnd(ENodeState::Success);
    return TaskNode::endExecute();
}

