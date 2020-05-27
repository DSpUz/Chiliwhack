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
#include "Surface.h"
#include "Animation.h"
#include "Timer.h"
#include "Field.h"
#include "SelectionMenu.h"
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
		Memesweeper
	};
	enum ChiliState
	{
		EMPTY,
		CHILI
	};
private:
	void ComposeFrame();
	void UpdateModel();
	/*-----------------------------------------------*/
	/*void DrawChili(int x,int y, int w); //x-coordinate, y- coordinate and width thanks to Legacy http://forum.planetchili.net/viewtopic.php?f=3&t=3890
	void DrawCell(int cellx, int celly, int sq_w, int line_g, int r, int g, int b);//Thanks to Asimov - see http://www.planetchili.net/forum/viewtopic.php?f=3&t=1065
	void DrawGrid(int posx, int posy, int cw,int rownumber);
	void DrawTimeline(int length, int height, int r, int g, int b);//Inspired by Maggot#9's Squares - see http://www.planetchili.net/forum/viewtopic.php?t=3856
	void DrawHammer1(int head_x, int head_y);//hammer up
	void DrawHammer2(int head_x, int head_y);//hammer down
	void DrawWelcomeScreen();
	void DrawDigit(int index,int x, int y);
	void DrawNumber(int x, int y);
	void DrawEndScreen();

	/*GAME LOGIC FUNCTIONS - for elaborate explanation see old beginner series lesson 12*/
	/*void SetCellState(int index, ChiliState state);// sets cells to either empty or chili
	void SetCellState(int ix, int iy, ChiliState state);

	ChiliState GetCellState(int index);//reads cell state according to index
	ChiliState GetCellState(int ix, int iy);

	void DoAIMoveRand();
	void DoUserInput();*/
	void CreateField(int width, int height, int cellwidth, Field::Mode mode, const PixelFont& font);
	void DestroyField();

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
	Timer ft;
	Surface surf = Surface("hammer240x170.bmp");
	Animation marleRight = Animation({ 0,0 }, 240, 170, 8, surf, 0.02f, Colors::Magenta);
	/*Database db;
	bool savedonce = false;
	bool loadedonce = false;
	PixelFont font;*/
	
	/********************************/
	/*const int baseX = 256;//grid top left corner coordinates
	const int baseY = 156;
	const int cellw = 144;//cell width for shifting chili and hammer
	float timeline_length=799;
	int line_r, line_g, line_b;//timeline colors
	int hammerx, hammery;//hammer coordinates

	int ChiliMoveX; //AI Chili coordinates
	int ChiliMoveY;
	PixelFont font;
	std::string welcometext = "welcome to chiliwhack 2.0!";

	ChiliState s0, s1, s2, s3, s4, s5, s6, s7, s8; //State variables for each cell
	bool keysPressedLastFrame,gotStarttime=false;
	bool start = false;
	Sound sky,slam,chi;//intro,hammer sound, outro
	bool intropl = false, slampl = false, chipl = false;//intro played variable 
	

	
	int chilicounter=0;//counts how many chili's you got
	int start_t, cond_t, curr_t;

	bool outro = false;
	int outrow=100;//width of chili in the outro
	bool end = false;*/
	/*  User Variables              */
	/********************************/
};