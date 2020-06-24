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
	void CreateField(int width, int height, int cellwidth, Field::Mode mode, const PixelFont& font);
	void DestroyField();
	void ResetTimeline();
	void readplayername(const Keyboard::Event& e,char*& playername, int& charcounter);
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

	Field::Mode modeplayed;
	Database db;
	bool savedonce = false;
	bool loadedonce = false;

	float timer=0.0f;
	const float gametime = 2.0f;
	const float colorscaling = 255 / gametime;
	RectI timeline;
	Color tcol;//timeline color
	float line_r, line_g;//timeline colors
	float line_right;


	int chiliwidth = 30;
	bool outroonce=false;
	Sound chili_t,slam,chi;//intro,hammer sound, outro
	bool intropl = false, slampl = false, chipl = false;//intro played variable 

	char namebuffer[18];
	char* namepointer = namebuffer;
	int curNameSize=0;
	
	int chilicounter=0;//counts how many chili's you got



	/*  User Variables              */
	/********************************/
};