#include "Environment.h"

void Environment::CalculateFloorCeiling(Ray rays[])
{
	for (int i = 0; i < 60; i++) {
		int ceiling = (float)(Graphics::ScreenHeight / 2.0) - Graphics::ScreenHeight / ((float)rays[i].distanceToWall);
		int floor = Graphics::ScreenHeight - ceiling;

		for (int y = 0; y < Graphics::ScreenHeight; y++) {
			if (y <= ceiling) {

			}
				
			else if (y > ceiling && y <= floor) {

			}
				
			else // Floor
			{
				// Shade floor based on distance
				
			}
		}

	}
}
