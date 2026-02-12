#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"

class AIQuitTask : public TaskNode {
public:
	AIQuitTask() = default;
	AIQuitTask(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~AIQuitTask() override = default;

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


