#pragma once
#include "Graphics.h"
#include "Vec2.h"
class RDot
{
public:
	void Draw(Graphics& gfx);
	void Update(int x, int y);
	int GetXCoord();
	int GetYCoord();
private:
	//Origin coordinates
	int orgX = 300;
	int orgY = 300;
	Vec2 pos = { 300, 300 };
	//Radius length
	int radius = 10;
	int fov = 4;
};

