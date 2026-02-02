#pragma once
#include "Pawn.h"

class Baker : public Pawn {
public:
	Baker();
	Baker(float posX_, float posY_, float sizeX, float sizeY, float speed_, std::string file);
	
	void update(float dt, Shop* shop) override;

public:
	bool direction = true;
};

