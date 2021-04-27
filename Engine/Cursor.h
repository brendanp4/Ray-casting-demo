#pragma once
#include "Graphics.h"
#include "RDot.h"
#include "Field.h"
#include "Vei2.h"
#include <vector>

class Ray
{
public:
	bool bHitWall = false;
	int distanceToWall = 200;
	const int rayCount = 80;
};

class Cursor
{
public:

	void Draw(Graphics& gfx);
	void DrawPlayArea(Graphics& gfx, Ray rays[]);
	void Update();
	void CastRay(RDot& dot, Graphics& gfx, Field& field);
	void DrawRay(Graphics& gfx);
	double GetRayAngle();
	double MoveForwardX();
	double MoveForwardY();
	void MoveBackward();
	void LookRight();
	void LookLeft();
	static constexpr int rayCount = 80;
	Ray rays[rayCount];
private:
	//Origin coordinates
	int orgX = 300;
	int orgY = 300;
	//Ray coordinates
	int rayX = 0;
	int rayY = 0;
	//Radius length
	int radius = 5;

	double forwardX;
	double forwardY;

	//
	static constexpr int depth = 100;
	
	double dFov = 3.14159f / 4.0;
	double rayAngle = 0;
	double inputAngle = 0;
	double playerAngle = 0;
	double ratio = 0;
	float fEyeX;
	float fEyeY;
	//std::vector<Ray> rays;
	

};

