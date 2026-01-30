#pragma once
#include "Pawn.h"

class Npc : public Pawn{
public:
	Npc();
	Npc(float posX_, float posY_, float sizeX, float sizeY, float speed_, std::string file);

	void update(float dt, Bakery* shop) override;
	void moveTo(float dt, Bakery* shop);

public:
	Bakery* shop_;
	bool arrived = false;
};

