#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"

class WaitForNpcTask : public TaskNode{
	public:
	WaitForNpcTask() = default;
	WaitForNpcTask(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~WaitForNpcTask() override = default;
	virtual void beginExecute() override;
	virtual void tick(float dt) override;
	virtual void endExecute() override;

private:
	bool isActive = false;
};

