#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"

class WaitTask : public TaskNode {
public:
	WaitTask() = default;
	WaitTask(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~WaitTask() override = default;

	virtual void beginExecute(float dt) override;	// y'a un bleme ici
	virtual void tick(float dt) override;
	virtual void endExecute() override;

private:
	float timer;
	float actual;
	float startPoint;

	int x;
	int y;

	int speed;
};


