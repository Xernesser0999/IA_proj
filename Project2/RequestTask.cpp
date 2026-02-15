#include "RequestTask.h"

RequestTask::RequestTask(FluxNode* parent, BehaviourTree* bt) 
    : TaskNode(parent, bt){

    sceneManager = SceneManager::GetSceneManager();
}

RequestTask::~RequestTask(){
    if (dial_ != nullptr) {
        if (sceneManager->getState() == day) {
            auto it = std::find(Day::StaticDrawble.begin(), Day::StaticDrawble.end(), dial_);
            if (it != Day::StaticDrawble.end()) {
                *it = nullptr;
            }
        }
        delete dial_;
        dial_ = nullptr;
    }

    if (dialog != nullptr) {
        delete dialog;
        dialog = nullptr;
    }
}



void RequestTask::beginExecute() {
    auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
    x = blackboard->coorNpcX;
    y = blackboard->coorNpcY;
    dial_ = new DialogBox(x - 50, y - 80, 150, 45);
    if (sceneManager->getState() == day) {
        Day::StaticDrawble.push_back(dial_);
    }

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
    isActive = false;
    if (sceneManager->getState() == day) {
        auto it = std::find(Day::StaticDrawble.begin(), Day::StaticDrawble.end(), dial_);
        if (it != Day::StaticDrawble.end()) {
            *it = nullptr;
        }
    }
    if (dial_) {
        delete dial_;
        dial_ = nullptr;
    }
    getParent()->onChildWorkEnd(ENodeState::Failure);
}



