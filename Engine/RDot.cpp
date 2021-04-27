#include "RDot.h"

void RDot::Draw(Graphics & gfx)
{
	int n = 2 * radius + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = i - radius;
			int y = j - radius;
			if (x * x + y * y <= radius * radius + 1) {
				gfx.PutPixel(x + orgX, y + orgY, 185, 30, 0);
			}
		}
	}
}

void RDot::Update(int x, int y)
{
	if (orgX - radius < 5) {
		orgX = orgX - radius;
	}
	else
	{
		orgX = x;
		orgY = y;
	}
	pos.x = x;
	pos.y = y;
}

int RDot::GetXCoord()
{
	return orgX;
}

int RDot::GetYCoord()
{
	return orgY;
}
