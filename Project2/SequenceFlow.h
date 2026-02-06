#pragma once

#include "FluxNode.h"

class SequenceFlow : public FluxNode{
public:
	SequenceFlow() = default;
	SequenceFlow(FluxNode* parent, BehaviourTree* bt = nullptr);
	SequenceFlow(FluxNode* parent, const std::vector<Node*>& children, BehaviourTree* bt);
	virtual ~SequenceFlow() override = default;

	virtual void onChildWorkEnd(ENodeState childState) override;

};

