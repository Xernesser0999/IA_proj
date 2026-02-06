#pragma once
#include <vector>
#include <iostream>

class FluxNode;
class BehaviourTree;

enum class ENodeState {
    Unknown = 0,
	Success = 1,
	Failure = 2,
	Abort = 3
};

class Node{
public:
    Node() = default;
    Node(FluxNode* parent, BehaviourTree bt);
    virtual ~Node() = default;

    virtual void beginExecute();
    virtual void tick(float dt);
	virtual void endExecute();

    virtual void abort();
    FluxNode* getParent() const;
    BehaviourTree* getBehaviourTree() const;

private:
    FluxNode* parent;
    BehaviourTree* behaviourTree;
};

