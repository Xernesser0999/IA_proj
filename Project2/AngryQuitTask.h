#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"
#include "DialogBox.h"

#include <SFML/Graphics.hpp>
#include <optional>

class AngryQuit : public TaskNode {
public:
	AngryQuit() = default;
	AngryQuit(FluxNode* parent, BehaviourTree* bt = nullptr);
	virtual ~AngryQuit() override;

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