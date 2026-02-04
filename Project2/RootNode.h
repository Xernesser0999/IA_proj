#pragma once
#include "Node.h"

class RootNode : public Node {
public:
    RootNode() = default;
	RootNode(FluxNode* childNode);
    virtual ~RootNode() override = default;

	virtual void beginExecute() override;
    virtual void tick(float dt) override;

	void setChild(FluxNode* rootChild);

public:
    FluxNode* child;
};
