#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"

class MoveToTask : public TaskNode {
public:
	MoveToTask() = default;
	MoveToTask(FluxNode* parent);
	virtual ~MoveToTask() override = default;

	virtual void beginExecute() override;
	virtual void tick(float dt) override;
	virtual void endExecute() override;

private:
	int targetX;
	int targetY;

	int x;
	int y;

	int speed;
};

