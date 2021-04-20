/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!paused) {
		mLocX = wnd.mouse.GetPosX();
		mLocY = wnd.mouse.GetPosY();
		player.Update(mLocX, mLocY);

		if (wnd.kbd.KeyIsPressed('W')) {
			rY -= 5;
		}
		if (wnd.kbd.KeyIsPressed('S')) {
			rY += 5;
		}
		if (wnd.kbd.KeyIsPressed('A')) {
			rX -= 5;
		}
		if (wnd.kbd.KeyIsPressed('D')) {
			rX += 5;
		}

		red.Update(rX, rY);


		if (wnd.mouse.LeftIsPressed()) {
			int x = wnd.mouse.GetPosX();
			int y = wnd.mouse.GetPosY();
			field.OnShadeClick(x, y);
		}


		if (wnd.kbd.KeyIsPressed(VK_SHIFT)) {
			if (!shift) {
				shift = true;
			}
			else
			{
				shift = false;
			}
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		if (!paused) {
			paused = true;
		}
		else
		{
			paused = false;
		}
	}



}

void Game::ComposeFrame()
{
	field.Draw(gfx);
	player.Draw(gfx);
	red.Draw(gfx);
	if (shift) {
		player.CastRay(red, gfx, field);
	}
}
