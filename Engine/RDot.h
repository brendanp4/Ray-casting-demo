#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Field.h"
class RDot
{
public:
	void Draw(Graphics& gfx);
	void Update(int x, int y);
	int GetXCoord();
	int GetYCoord();
	void DetectCollision(Field& field);
	bool cTop = false;
	bool cBottom = false;
	bool cLeft = false;
	bool cRight = false;
private:
	//Origin coordinates
	int orgX = 300;
	int orgY = 300;
	Vec2 pos = { 300, 300 };
	//Radius length
	int radius = 10;
	int fov = 4;
	
};

