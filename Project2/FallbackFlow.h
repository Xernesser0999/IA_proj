#pragma once
#include "FluxNode.h"

class FallbackFlow : public FluxNode{
public:
	FallbackFlow() = default;
	FallbackFlow(FluxNode* parent, BehaviourTree* bt = nullptr);
	FallbackFlow(FluxNode* parent, const std::vector<Node*>& children, BehaviourTree* bt);
	virtual ~FallbackFlow() override = default;

	virtual void onChildWorkEnd(ENodeState childState) override;
};

