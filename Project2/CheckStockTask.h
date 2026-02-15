#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"

class CheckStockTask : public TaskNode {
public:
	CheckStockTask() = default;
	CheckStockTask(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~CheckStockTask() override = default;

	virtual void beginExecute() override;
	virtual void tick(float dt) override;
	virtual void endExecute() override;
};

