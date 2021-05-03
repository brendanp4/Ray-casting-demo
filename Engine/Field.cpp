#include "Field.h"
#include <fstream>

void Field::Cell::Shade()
{
	state = State::shaded;
	shaded = true;
}

bool Field::Cell::CheckShade()
{
	if (state == State::shaded) {
		return true;
	}
	else {
		return false;
	}
}


void Field::Cell::Draw(Graphics& gfx, int posX, int posY)
{
	for (int i = 0; i < cLength; i++) {
		for (int j = 0; j < cWidth; j++) {

			switch (state)
			{
			case Field::Cell::State::blank:
				gfx.PutPixel(i + posX, j + posY, 0, 0, 50);
				break;
			case Field::Cell::State::shaded:
				gfx.PutPixel(i + posX, j + posY, 40, 70, 70);
				break;
			default:
				break;
			}

		}
	}
}

void Field::OnShadeClick(int x, int y)
{
	int gridPosX = x / 20;
	int gridPosY = y / 20;
	CellAt(gridPosX, gridPosY).Shade();
}

void Field::Draw(Graphics& gfx)
{
	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 30; y++) {
			Cell current = CellAt(x, y);
			current.Draw(gfx, x * 20, y * 20);
		}
	}
}

bool Field::IsInCell(int x, int y)
{
	if (CellAt(x, y).shaded == true) {
		return true;
	}
	else {
		return false;
	}
	
}

void Field::WriteToFile()
{
	std::ofstream map;
	map.open("map.txt");
	int counter = 1;
	for (Cell cell : grid) {
		if (cell.shaded) {
			map << "#";
		}
		else
		{
			map << "0";
		}
		if (counter == 40) {
			map << "\n";
			counter = 0;
		}
		counter++;
	}
	map.close();
}


Field::Cell & Field::CellAt(int x, int y)
{
	return grid[y * width + x];
}
