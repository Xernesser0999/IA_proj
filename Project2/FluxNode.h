#pragma once
#include "Node.h"

class FluxNode : public Node {
public:
    FluxNode() = default;
	FluxNode(FluxNode* parent, BehaviourTree* bt);
	FluxNode(FluxNode* parent, const std::vector<Node*>& children, BehaviourTree* tree);
    virtual ~FluxNode() = default;

	virtual void addChild(Node* child);
	virtual void removeChild(Node* child);

	virtual void beginExecute() override;
	virtual void tick(float dt) override;
	virtual void onChildWorkEnd(ENodeState childState);

public:
    std::vector<Node*> childNodes;
	Node* currentExecuteChild;
};

