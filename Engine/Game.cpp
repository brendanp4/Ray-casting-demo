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
		//mLocX = wnd.mouse.GetPosX();
		//mLocY = wnd.mouse.GetPosY();
		//player.Update(mLocX, mLocY);

		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			player.LookRight();
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			player.LookLeft();
		}
		if (wnd.kbd.KeyIsPressed('W')) {
			rX += player.MoveForwardX() * 2;
			rY += player.MoveForwardY() * 2;
		}
		if (wnd.kbd.KeyIsPressed('S')) {
			rY += 1;
		}
		if (wnd.kbd.KeyIsPressed('A')) {
			rX -= 1;
		}
		if (wnd.kbd.KeyIsPressed('D')) {
			rX += 1;
		}
		if (wnd.kbd.KeyIsPressed('M')) {
			toggleMap(mapOpen);
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
		red.Update(rX, rY);


		if (wnd.mouse.LeftIsPressed()) {
			int x = wnd.mouse.GetPosX();
			int y = wnd.mouse.GetPosY();
			field.OnShadeClick(x, y);
		}
		
	}


	std::string angle = std::to_string(player.GetRayAngle()) + " degrees";
	std::string coordx = std::to_string(player.MoveForwardX());
	std::string coordy = std::to_string(player.MoveForwardY());
	std::string coords = coordx +  " " +coordy;
	wnd.SetText(coords);
	


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

void Game::toggleMap(bool & mapOpen)
{
	if (mapOpen) {
		mapOpen = false;
	}
	else
	{
		mapOpen = true;
	}
}

void Game::ComposeFrame()
{
	if (mapOpen) {
		field.Draw(gfx);
		//player.Draw(gfx);
		red.Draw(gfx);
	}
	player.CastRay(red, gfx, field);
	if (!mapOpen) {
		player.DrawPlayArea(gfx, player.rays);
	}
	
	
}
