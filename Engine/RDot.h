#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Field.h"
class RDot
{
public:
	void Draw(Graphics& gfx);
	void DrawCrosshair(Graphics& gfx);
	void Shoot(Graphics& gfx);
	void Update(double x, double y);
	double GetXCoord();
	double GetYCoord();
	void DetectCollision(Field& field);
	bool cTop = false;
	bool cBottom = false;
	bool cLeft = false;
	bool cRight = false;
private:
	//Origin coordinates
	double orgX = 300;
	double orgY = 300;
	Vec2 pos = { 300, 300 };
	//Radius length
	int radius = 10;
	int fov = 4;
	
};

