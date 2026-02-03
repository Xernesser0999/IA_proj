#pragma once
#include <vector>
#include <iostream>

class FluxNode;

enum class ENodeState {
    Unknown = 0,
	Success = 1,
	Failure = 2,
	Abort = 3
};

class Node{
public:
    Node() = default;
    Node(FluxNode* parent);
    virtual ~Node() = default;

    virtual void beginExecute();
    virtual void tick(float dt);
	virtual void endExecute();

    virtual void abort();
    FluxNode* getParent() const;

private:
    FluxNode* parent;
};

