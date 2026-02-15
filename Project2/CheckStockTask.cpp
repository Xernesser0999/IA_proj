#include "CheckStockTask.h"


CheckStockTask::CheckStockTask(FluxNode* parent, BehaviourTree* bt)
    : TaskNode(parent, bt) {
}

void CheckStockTask::beginExecute() {
    tick(0.f);
}

void CheckStockTask::tick(float dt) {
    endExecute();
}

void CheckStockTask::endExecute() {
    auto* bb = static_cast<ShopBlackBoard*>(getBehaviourTree()->getBlackboard());

    bb->npcRequest = false;
    bb->result = true;

    if (bb->stock > 0) {
        bb->stock -= 1;
        bb->sale = true;
        getParent()->onChildWorkEnd(ENodeState::Success);
    }
    else {
        bb->sale = false;
        getParent()->onChildWorkEnd(ENodeState::Failure);
    }
}
