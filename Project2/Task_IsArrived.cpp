#include "Task_IsArrived.h"



IsArrived::IsArrived(FlowNode* ParentNode) : TaskNode(ParentNode) {
}

void IsArrived::BeginExecute() {
    TaskNode::BeginExecute();
}

void IsArrived::Tick(float DeltaTime) {
    TaskNode::Tick(DeltaTime);

	float targetX = shop->pos.x + shop->size.x - 300;
	float targetY = shop->pos.y + shop->size.y - 80;

	if (posX == targetX && posY == targetY) {
		arrived = true;
		return;
	}

	if (posX < targetX) {
		posX += speed * dt;
		if (posX > targetX) {
			posX = targetX;
		}
	}
	else if (posX > targetX) {
		posX -= speed * dt;
		if (posX < targetX) {
			posX = targetX;
		}
	}
	else if (posY < targetY) {
		posY += speed * dt;
		if (posY > targetY) {
			posY = targetY;
		}
	}
	else if (posY > targetY) {
		posY -= speed * dt;
		if (posY < targetY) {
			posY = targetY;
		}
	}
}

ENodeState IsArrived::EndExecute() {
    return TaskNode::EndExecute();
}
