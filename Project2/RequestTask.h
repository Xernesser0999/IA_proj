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
	sf::RectangleShape* dialog = nullptr;
	DialogBox* dial_ = nullptr;

	float dt;
	float x = 0.f;
	float y = 0.f;
	GameObjects* targetShop = nullptr;
	ShopBlackBoard* shopBb = nullptr;
	bool isActive = false;
	bool shopDone = false;
	SceneManager* sceneManager = nullptr;
};