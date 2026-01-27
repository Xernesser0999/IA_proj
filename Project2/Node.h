#pragma once
#include <vector>
#include <iostream>

class Node{
public:
    Node();
    virtual ~Node();

    virtual void tick(float DeltaTime);
    virtual void begin();
};

