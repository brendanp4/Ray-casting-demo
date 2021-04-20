#pragma once
#include "Graphics.h"
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
	//Radius length
	int radius = 10;
};

