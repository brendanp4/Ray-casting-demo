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

void Cursor::Update(int x, int y)
{
	if (orgX - radius <= 5) {
		orgX = 5 + radius;
	}
	else
	{
		orgX = x;
		orgY = y;
	}
	
}

void Cursor::CastRay(RDot & dot, Graphics& gfx, Field& field)
{
	int dotX = dot.GetXCoord();
	int dotY = dot.GetYCoord();

	double run = 0;

	if (orgX < dotX) {
		run = orgX - dotX;
	}
	else if (orgX > dotX) {
		run = orgX - dotX;
	}
	double rise = orgY - dotY;
	double hypot = sqrt((run * run) + (rise * rise));
	double slope = rise / run;
	for (int i = 0; i < hypot; i++)
	{
		if (dotX < orgX) {
			if ((dotX + i) <= orgX) {
				rayX = dotX + i;
				rayY = dotY + (i * slope);
				gfx.PutPixel(rayX, rayY, 110, 55, 255);
				// Pass values

				int pX = rayX / 20;
				int pY = rayY / 20;

				if (field.IsInCell(pX, pY)) {
					for (int i = 0; i < 8; i++) {
						for (int j = 0; j < 8; j++) {
							gfx.PutPixel((rayX - 4) + i, (rayY + 4) - j, 255, 255, 255);
						}
					}
					break;
					
				}
			}
		}
		if (dotX > orgX) {
			if ((dotX - i) >= orgX) {
				rayX = dotX - i;
				rayY = dotY + (i * -slope);
				gfx.PutPixel(rayX, rayY , 110, 55, 255);

				int pX = rayX / 20;
				int pY = rayY / 20;

				if (field.IsInCell(pX, pY)) {
					for (int i = 0; i < 8; i++) {
						for (int j = 0; j < 8; j++) {
							gfx.PutPixel((rayX - 4) + i, (rayY + 4) - j, 255, 255, 255);
						}
					}
					break;

				}
			}
		}

	}
}