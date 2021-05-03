#pragma once
#include "Graphics.h"

class Field
{
private:
	class Cell
	{
	public:
		enum class State {
			blank,
			shaded
		};
		
	public:
		const int cLength = 20;
		const int cWidth = 20;
		void Draw(Graphics& gfx, int posX, int posY);
		void Shade();
		bool CheckShade();
		State state = State::blank;
		bool shaded = false;

	};



public:
	void OnShadeClick(int x, int y);
	void Draw(Graphics& gfx);
	bool IsInCell(int x, int y);
	void WriteToFile();

private:
	static constexpr int width = 800 / 20;
	static constexpr int height = 600 / 20;
	Cell grid[width * height];
	Cell& CellAt(int x, int y);

};

