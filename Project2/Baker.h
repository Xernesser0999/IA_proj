#pragma once
#include "Pawn.h"

class Baker : public pawn{
	public:


		bool direction = true;

		Baker(float posX_, float posY_, std::string file);
		void update(float dt) override;
};

