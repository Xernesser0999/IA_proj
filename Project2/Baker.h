#pragma once
#include "Pawn.h"

class Baker : public pawn{
public:
	Baker(float posX_, float posY_, std::string file);
	
	void update(float dt) override;

public:
	bool direction = true;
};

