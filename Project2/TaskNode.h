#pragma once
#include "Node.h"
#include "FluxNode.h"

class TaskNode : public Node {
public:
    TaskNode() = default;
    TaskNode(FluxNode* parent, BehaviourTree* bt = nullptr);
    virtual ~TaskNode() = default;

};