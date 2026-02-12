#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"
#include "DialogBox.h"

#include <SFML/Graphics.hpp>
#include <optional>

class AiStop : public TaskNode {
public:
	AiStop() = default;
	AiStop(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~AiStop() override;

	virtual void beginExecute() override;
	virtual void tick(float dt) override;
	virtual void endExecute() override;

private:

};