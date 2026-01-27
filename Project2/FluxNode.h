#pragma once
#include "Node.h"

class FluxNode : public Node {
public:
    FluxNode();
    ~FluxNode() override;

    void tick(float DeltaTime) override;
    virtual void onNodeEnd();

public:
    std::vector<Node*> childNodes;
    Node* actualNode = nullptr;
};

