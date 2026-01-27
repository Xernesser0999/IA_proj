#pragma once
#include "Node.h"

class RootNode : public Node {
public:
    RootNode();
    ~RootNode() override;

    void tick(float DeltaTime) override;

public:
    Node* childNode;
};
