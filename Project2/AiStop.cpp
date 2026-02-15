#include "AiStop.h"

AiStop::AiStop(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

AiStop::~AiStop() {

}

void AiStop::beginExecute() {
    auto blackboard = static_cast<NpcBlackBoard*>(getBehaviourTree()->getBlackboard());
}

void AiStop::tick(float dt_) {
    endExecute();
}

void AiStop::endExecute() {
}

