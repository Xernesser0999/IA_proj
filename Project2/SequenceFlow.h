#pragma once
#include "FluxNode.h"

class SequenceFlow : public  FlowNode {
public:
    SequenceFlow() = default;
    SequenceFlow(FlowNode* ParentNode);
    SequenceFlow(FlowNode* ParentNode, const std::vector<Node*>& Childs);
    virtual ~SequenceFlow() override = default;

    virtual void OnChildWorkEnd(ENodeState ChildState) override;
};
