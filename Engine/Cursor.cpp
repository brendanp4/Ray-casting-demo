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
	for (int i = 0; i < rayCount; i++) {
		double ceiling = ((double(Graphics::ScreenHeight) / 2.0) - (double(Graphics::ScreenHeight) / rays[i].distanceToWall));
		//int ceiling = int(300 - int(float(Graphics::ScreenHeight) / float(rays[i].distanceToWall)));
		double floor = Graphics::ScreenHeight - ceiling;

		for (int y = 0; y < Graphics::ScreenHeight; y++) {
			if (y <= ceiling) {
				for (int j = 0; j < 2; j++) {
					gfx.PutPixel((i * 2) + j, y, 190, 190, 190);
				}
			}

			else if (y > ceiling && y <= floor) {
				for (int j = 0; j < 2; j++) {
					gfx.PutPixel((i * 2) + j, y, 160, 160, 55);
				}
			}

			else
			{
	
				int gradientR = int(float(y) / 3.5);
				
				for (int j = 0; j < 2; j++) {
					gfx.PutPixel((i * 2) + j, y, 170 - gradientR, 170 - gradientR, 170 - gradientR);
					
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
	double playerX = dot.GetXCoord();
	double playerY = dot.GetYCoord();
	

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

		double ca = 0;

		double stepSize = 0.1;
		double counter = 0.0;
		while (counter < depth)
		{

			rayX = int(playerX + (counter * unitRayX));
			rayY = int(playerY + (counter * unitRayY));

			gfx.PutPixel(int(rayX), int(rayY), 110, 55, 255);

			int pX = rayX / 20;
			int pY = rayY / 20;

			if (field.IsInCell(pX, pY)) {

				ca = playerAngle - rayAngle;
				if (ca < 0) {
					ca += (2.0 * 3.14159);
				}
				if (ca > (2.0 * 3.14159)) {
					ca -= (2.0 * 3.14159);
				}
				double distToWall = counter * cos(ca);
				rays[f].bHitWall = true;
				rays[f].distanceToWall = distToWall;


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
			
			counter += stepSize;
		}

		/*for (int i = 0; i < depth; i++)
		{
			rayX = int(playerX + (i * unitRayX));
			rayY = int(playerY + (i * unitRayY));

			gfx.PutPixel(int(rayX), int(rayY), 110, 55, 255);

			int pX = rayX / 20;
			int pY = rayY / 20;

			if (field.IsInCell(pX, pY)) {

				ca = playerAngle - rayAngle;
				if (ca < 0) {
					ca += (2.0 * 3.14159);
				}
				if (ca > (2.0 * 3.14159)) {
					ca -= (2.0 * 3.14159);
				}
				distToWall = double(i) * cos(ca);
				rays[f].bHitWall = true;
				rays[f].distanceToWall = distToWall;


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

		}*/
	}
}

void Cursor::DrawRay(Graphics & gfx)
{
}

double Cursor::GetRayAngle()
{
	return ((rayAngle - dFov / 2.0) * 180) / 3.14159;
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
	playerAngle += .035;
	if (playerAngle > (2 * 3.14159)) {
		playerAngle = 0;
	}
}

void Cursor::LookLeft()
{
	playerAngle -= .035;
	if (playerAngle < 0) {
		playerAngle = 2 * 3.14159;
	}
}
