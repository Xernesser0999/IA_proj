#pragma once
#include "Pawn.h"

class Baker : public Pawn {
public:
	Baker();
	Baker(float posX_, float posY_, float sizeX, float siezY, std::string file);
	
	void update(float dt) override;

public:
	bool direction = true;
};

