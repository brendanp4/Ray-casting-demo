#include "Cursor.h"
#include <math.h>


void Cursor::Draw(Graphics & gfx)
{
	int n = 2 * radius + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = i - radius;
			int y = j - radius;
			if (x * x + y * y <= radius * radius + 1) {
				gfx.PutPixel(x + orgX, y + orgY, 120, 130, 255);
			}
		}
	}
	
}

void Cursor::DrawPlayArea(Graphics & gfx, Ray rays[])
{
	for (int i = 0; i < 80; i++) {
		int ceiling = (float)(Graphics::ScreenHeight / 2.0) - Graphics::ScreenHeight / ((float)rays[i].distanceToWall);
		int floor = Graphics::ScreenHeight - ceiling;

		for (int y = 0; y < Graphics::ScreenHeight; y++) {
			if (y <= ceiling) {
				for (int j = 0; j < 10; j++) {
					gfx.PutPixel((i * 10) + j, y, 190, 190, 190);
				}
			}

			else if (y > ceiling && y <= floor) {
				for (int j = 0; j < 10; j++) {
					gfx.PutPixel((i * 10) + j, y, 120, 160, 255);
				}
			}

			else// Floor
			{
				// Shade floor based on distance
				int gradientR = y / 3.5;
				
				for (int j = 0; j < 10; j++) {
					gfx.PutPixel((i * 10) + j, y, 170 - gradientR, 170 - gradientR, 170 - gradientR);
						//gfx.PutPixel(j, (y * 10) + j, 166, 157, 157);

					//else if (y < 400) {
					//	gfx.PutPixel((i * 10) + j, y, 141, 136, 136);
					//	//gfx.PutPixel(j, (y * 10) + j, 141, 136, 136);
					//}
					//else if (y < 500) {
					//	gfx.PutPixel((i * 10) + j, y, 115, 111, 111);
					//	//gfx.PutPixel(j, (y * 10) + j, 115, 111, 111);
					//}
					//else {
					//	gfx.PutPixel((i * 10) + j, y, 90, 85, 85);
					//	//gfx.PutPixel(j, (y * 10) + j, 90, 85, 85);
					//}
					
				}
			}
		}

	}
}

void Cursor::Update()
{
	playerAngle = (playerAngle * 3.14159) / 180;
}

void Cursor::CastRay(RDot & dot, Graphics& gfx, Field& field)
{
	int playerX = dot.GetXCoord();
	int playerY = dot.GetYCoord();
	

	int start = rayCount / 2;
	forwardX = cos(playerAngle);
	forwardY = sin(playerAngle);

	

	for (int f = 0; f < rayCount; f++) {
		// Get x, y, and magnitude of vector
		double run = orgX - playerX;
		double rise = orgY - playerY;
		double hypot = sqrt((run * run) + (rise * rise));


		//playerAngle = atan(rise / run);
		rayAngle =  (playerAngle - dFov / 2.0) + (double(f) / double(rayCount)) * dFov;
		double unitRayX = cos(rayAngle);
		double unitRayY = sin(rayAngle);
		

		bool bHitWall = false;
		int distToWall = depth;

		for (int i = 0; i < depth; i++)
		{
			rayX = playerX + (i * unitRayX);
			rayY = playerY + (i * unitRayY);
			//if (playerX < orgX) {
			//
			//		rayX = playerX + (i * unitRayX);
			//		rayY = playerY + (i * unitRayY);
			//}
			//else if (playerX > orgX) {
			//
			//		rayX = playerX - (i * unitRayX);
			//		rayY = playerY + (i * -unitRayY);
			//}
			
			gfx.PutPixel(int(rayX), int(rayY), 110, 55, 255);

			int pX = rayX / 20;
			int pY = rayY / 20;

			if (field.IsInCell(pX, pY)) {

				//bHitWall = true;
				//distToWall = sqrt(rayX * rayX + rayY * rayY);
				rays[f].bHitWall = true;
				rays[f].distanceToWall = i;


				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						gfx.PutPixel((rayX - 4) + i, (rayY + 4) - j, 255, 255, 255);
					}
				}
				break;

			}
			else
			{
				rays[f].bHitWall = false;
				rays[f].distanceToWall = depth;
			}

		}
	}
}

void Cursor::DrawRay(Graphics & gfx)
{
}

double Cursor::GetRayAngle()
{
	return (rayAngle * 180) / 3.14159;
}

double Cursor::MoveForwardX()
{
	return forwardX;
}

double Cursor::MoveForwardY()
{
	return forwardY;
}

void Cursor::LookRight()
{
	playerAngle += .1;
}

void Cursor::LookLeft()
{
	playerAngle -= .1;
}
