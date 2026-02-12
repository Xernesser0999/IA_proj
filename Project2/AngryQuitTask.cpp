#include "AngryQuitTask.h"

#include "Morning.h"


AngryQuit::AngryQuit(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

AngryQuit::~AngryQuit() {
    if (dial_ != nullptr) {
        auto it = std::find(Morning::StaticDrawble.begin(), Morning::StaticDrawble.end(), dial_);
        if (it != Morning::StaticDrawble.end()) {
            *it = nullptr;
        }
        delete dial_;
        dial_ = nullptr;
    }

    if (dialog != nullptr) {
        delete dialog;
        dialog = nullptr;
    }
}

void AngryQuit::beginExecute() {
    auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
    x = blackboard->coorNpcX;
    y = blackboard->coorNpcY;
    dial_ = new DialogBox(x - 110, y - 80, 200, 45);
    Morning::StaticDrawble.push_back(dial_);

    startPoint = 0.0f;
    timer = 2.0f;
    isActive = true;
}

void AngryQuit::tick(float dt_) {
    if (!isActive)
        return;

    auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
    if (dial_ && dial_->dialog) {
        x = blackboard->coorNpcX - 25;
        y = blackboard->coorNpcY - 50;
        dial_->text("Style, plus de pain..");
        dial_->dialog->setPosition(sf::Vector2f(x, y));
    }
    startPoint += dt_;

    if (startPoint >= timer) {
        endExecute();
    }
}

void AngryQuit::endExecute() {
    isActive = false;
    auto it = std::find(Morning::StaticDrawble.begin(), Morning::StaticDrawble.end(), dial_);
    if (it != Morning::StaticDrawble.end()) {
        *it = nullptr;
    }
    if (dial_) {
        delete dial_;
        dial_ = nullptr;
    }
    getParent()->onChildWorkEnd(ENodeState::Success);
    return TaskNode::endExecute();
}

