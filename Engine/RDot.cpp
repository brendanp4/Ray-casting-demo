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
	pos.x = float(x);
	pos.y = float(y);
}

int RDot::GetXCoord()
{
	return orgX;
}

int RDot::GetYCoord()
{
	return orgY;
}

void RDot::DetectCollision(Field& field)
{
	int topY = (orgY - 3) / 20;
	int topX = orgX / 20;
	int botY = (orgY + 3) / 20;
	int botX = orgX / 20;
	int leftX = (orgX - 3) / 20;
	int leftY = orgY / 20;
	int rightX = (orgX + 3) / 20;
	int rightY = orgY / 20;
	if (field.IsInCell(topX, topY)) {
		cTop = true;
	}
	else
	{
		cTop = false;
	}
	if (field.IsInCell(botX, botY)) {
		cBottom = true;
	}
	else
	{
		cBottom = false;
	}
	if (field.IsInCell(leftX, leftY)) {
		cLeft = true;
	}
	else
	{
		cLeft = false;
	}
	if (field.IsInCell(rightX, rightY)) {
		cRight = true;
	}
	else
	{
		cRight = false;
	}
}
