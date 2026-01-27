#pragma once
#include "Node.h"
#include "FluxNode.h"

class TaskNode : public Node {
public:
    TaskNode();
    virtual ~TaskNode();
    void begin() override;
    void tick(float deltaTime) override;
public:
    FluxNode* parentNode;
    float actualTime;
    float time;
};


