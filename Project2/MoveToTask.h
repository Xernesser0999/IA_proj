#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"

class MoveToTask : public TaskNode {
public:
	MoveToTask() = default;
	MoveToTask(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~MoveToTask() override = default;

	virtual void beginExecute() override;
	virtual void tick(float dt) override;
	virtual void endExecute() override;

private:
	float targetX;
	float targetY;

	float x;
	float y;

	float speed;
};


