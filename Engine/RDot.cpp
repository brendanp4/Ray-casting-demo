#include "RDot.h"

void RDot::Draw(Graphics & gfx)
{
	int n = 2 * radius + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = i - radius;
			int y = j - radius;
			if (x * x + y * y <= radius * radius + 1) {
				gfx.PutPixel(x + int(orgX), y + int(orgY), 185, 30, 0);
			}
		}
	}
}

void RDot::DrawCrosshair(Graphics & gfx)
{
	// center coordinates
	int centerX = Graphics::ScreenWidth / 2;
	int centerY = Graphics::ScreenHeight / 2;
	// crosshair radius
	int radius = 5;

	for (int i = -radius; i < radius + 1; i++) {
		gfx.PutPixel(centerX + i, centerY, 255, 255, 255);
	}
	for (int i = -radius; i < radius + 1; i++) {
		gfx.PutPixel(centerX, centerY + i, 255, 255, 255);
	}
}

void RDot::Shoot(Graphics & gfx)
{

}

void RDot::Update(double x, double y)
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

double RDot::GetXCoord()
{
	return orgX;
}

double RDot::GetYCoord()
{
	return orgY;
}

void RDot::DetectCollision(Field& field)
{
	int topY = (int(orgY) - 3) / 20;
	int topX = int(orgX) / 20;
	int botY = (int(orgY) + 3) / 20;
	int botX = int(orgX) / 20;
	int leftX = (int(orgX) - 3) / 20;
	int leftY = int(orgY) / 20;
	int rightX = (int(orgX) + 3) / 20;
	int rightY = int(orgY) / 20;
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
