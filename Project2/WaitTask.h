#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"
#include "DialogBox.h"

#include <SFML/Graphics.hpp>
#include <optional>

class WaitTask : public TaskNode {
public:
	WaitTask() = default;
	WaitTask(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~WaitTask() override = default;

	virtual void beginExecute() override;
	virtual void tick(float dt) override;
	virtual void endExecute() override;

private:
	float timer;
	float actual;
	float startPoint;
	sf::RectangleShape* dialog;
	DialogBox* dial_;
	
	sf::Clock clock;
	float dt;
	float x;
	float y;
	bool isActive = false;
};


