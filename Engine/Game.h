/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Sound.h"
#include "Database.h"
#include "Timer.h"
#include "Field.h"
#include "SelectionMenu.h"
#include "Hammer.h"
#include <assert.h>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	enum class State
	{
		SelectionMenu,
		Game,
		BerserkerChili,
		HighscoreTable,
		Endscreen
	};
private:
	void ComposeFrame();
	void UpdateModel();
	/*-----------------------------------------------*/
	/*void DrawChili(int x,int y, int w); //x-coordinate, y- coordinate and width thanks to Legacy http://forum.planetchili.net/viewtopic.php?f=3&t=3890
	void DrawCell(int cellx, int celly, int sq_w, int line_g, int r, int g, int b);//Thanks to Asimov - see http://www.planetchili.net/forum/viewtopic.php?f=3&t=1065

	/*GAME LOGIC FUNCTIONS - for elaborate explanation see old beginner series lesson 12*/
	/*void SetCellState(int index, ChiliState state);// sets cells to either empty or chili
	void SetCellState(int ix, int iy, ChiliState state);

	ChiliState GetCellState(int index);//reads cell state according to index
	ChiliState GetCellState(int ix, int iy);

	void DoAIMoveRand();
	void DoUserInput();*/
	void CreateField(int width, int height, int cellwidth, Field::Mode mode, const PixelFont& font);
	void DestroyField();
	void ResetTimeline();

	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	Field* pField = nullptr;
	bool fieldcreated = false;
	PixelFont font;
	SelectionMenu menu;
	State state = State::SelectionMenu;
	SelectionMenu::Gamemode mode;
	
	Timer ft;

	//Hammer hammer;

	Database db;
	bool savedonce = false;
	bool loadedonce = false;

	float timer=0.0f;
	const float gametime = 30.0f;
	const float colorscaling = 255 / gametime;
	RectI timeline;
	Color tcol;//timeline color
	float line_r, line_g;//timeline colors
	float line_right;


	int chiliwidth = 30;
	bool outroonce=false;
	Sound chili_t,slam,chi;//intro,hammer sound, outro
	bool intropl = false, slampl = false, chipl = false;//intro played variable 
	
	int chilicounter=0;//counts how many chili's you got

	/*  User Variables              */
	/********************************/
};