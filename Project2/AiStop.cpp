#include "AiStop.h"

AiStop::AiStop(FluxNode* parent, BehaviourTree* bt) : TaskNode(parent, bt) {
}

AiStop::~AiStop() {

}

void AiStop::beginExecute() {
    isActive = true;
}

void AiStop::tick(float dt_) {
}

void AiStop::endExecute() {
}

