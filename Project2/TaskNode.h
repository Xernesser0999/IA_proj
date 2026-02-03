#pragma once
#include "Node.h"
#include "FluxNode.h"

class TaskNode : public Node {
public:
    TaskNode() = default;
    TaskNode(FluxNode* parent);
    virtual ~TaskNode() = default;

};