#pragma once
#include "FluxNode.h"

class FallbackFlow : public FluxNode{
public:
	FallbackFlow() = default;
	FallbackFlow(FluxNode* parent);
	FallbackFlow(FluxNode* parent, const std::vector<Node*>& children);
	virtual ~FallbackFlow() override = default;

	virtual void onChildWorkEnd(ENodeState childState) override;
};

