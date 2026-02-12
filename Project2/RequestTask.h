#pragma once
#include "TaskNode.h"
#include "BehaviourTree.h"
#include "FluxNode.h"
#include "DialogBox.h"
#include "SceneManager.h"

#include <SFML/Graphics.hpp>
#include <optional>

class RequestTask : public TaskNode {
public:
	RequestTask() = default;
	RequestTask(FluxNode* parent, BehaviourTree* bt);
	virtual ~RequestTask() override;

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
	SceneManager* sceneManager = nullptr;
};