#pragma once
#include "Node.h"

class RootNode : public Node {
public:
    RootNode();
    virtual ~RootNode();

    void tick(float DeltaTime) override;

public:
    Node* childNode;
};
