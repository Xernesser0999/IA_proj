#pragma once
#include "FluxNode.h"

class FallbackFlow : public  FlowNode {
public:
    FallbackFlow() = default;
    FallbackFlow(FlowNode* ParentNode);
    FallbackFlow(FlowNode* ParentNode, const std::vector<Node*>& Childs);
    virtual ~FallbackFlow() override = default;

    virtual void OnChildWorkEnd(ENodeState ChildState) override;
};
