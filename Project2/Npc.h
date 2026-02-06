#pragma once
#include "Pawn.h"
#include "BehaviourTree.h"

class Npc : public Pawn{
public:
	Npc();
	Npc(float posX_, float posY_, float sizeX, float sizeY, float speed_, std::string file);

	void update(float dt, Shop* shop) override;
	void moveTo(float dt, Shop* shop);

public:
	Shop* shop_;
	bool arrived = false;
	NpcBlackBoard* bt;
};

