#pragma once
#include "Graphics.h"
#include "RDot.h"
#include "Field.h"
class Ray
{
public:
	void CastRay(RDot& player, Field& field, Graphics& gfx);
private:
	int x = 0;
	int y = 0;
};

