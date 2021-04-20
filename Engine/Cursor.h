#pragma once
#include "Graphics.h"
#include "RDot.h"
#include "Field.h"
class Cursor
{
public:
	void Draw(Graphics& gfx);
	void Update(int x, int y);
	void CastRay(RDot& dot, Graphics& gfx, Field& field);
private:
	//Origin coordinates
	int orgX = 300;
	int orgY = 300;
	//Ray coordinates
	int rayX = 0;
	int rayY = 0;
	//Radius length
	int radius = 5;

};

