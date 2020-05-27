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
#include <stdlib.h>
#include <time.h>
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	menu({ gfx.GetScreenRect().GetCenter().x,200 })
	/*hammerx(1),
	hammery(1),
	keysPressedLastFrame(false),
	sky(L"sky.wav"),
	slam(L"slam.wav"),
	chi(L"chi.wav")*/
{
	/*for (int index = 0; index<9; index++) {//initializes all cells empty
		SetCellState(index, EMPTY);
	}
	srand((unsigned int)time(NULL));//converts computer time since 1970 in a number and "seeds" random function*/
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::CreateField(int width, int height, int cellwidth, Field::Mode mode, const PixelFont& font)
{
	assert(pField == nullptr);
	pField = new Field(gfx.GetScreenRect().GetCenter(),width,height,cellwidth,mode,font);
}

void Game::DestroyField()
{
	delete pField;
	pField = nullptr;
}






/*GAME LOGIC FUNCTIONS - see old series beginner tutorial 12 */
/*void Game::SetCellState(int index, ChiliState state)
{
	switch (index)  //sets chosen cell to empty or chili
	{
	case 0:
		s0 = state;
		break;
	case 1:
		s1 = state;
		break;
	case 2:
		s2 = state;
		break;
	case 3:
		s3 = state;
		break;
	case 4:
		s4 = state;
		break;
	case 5:
		s5 = state;
		break;
	case 6:
		s6 = state;
		break;
	case 7:
		s7 = state;
		break;
	case 8:
		s8 = state;
		break;
	default:
		break;
	}
}
void Game::SetCellState(int ix, int iy, ChiliState state)
{
	int index = iy * 3 + ix;
	SetCellState(index, state);
}
Game:: ChiliState Game::GetCellState(int index)
{
	switch (index)
	{
	case 0:
		return s0;
		break;
	case 1:
		return s1;
		break;
	case 2:
		return s2;
		break;
	case 3:
		return s3;
		break;
	case 4:
		return s4;
		break;
	case 5:
		return s5;
		break;
	case 6:
		return s6;
		break;
	case 7:
		return s7;
		break;
	case 8:
		return s8;
		break;
	default:
		return EMPTY;
	}
}
Game:: ChiliState Game::GetCellState(int ix, int iy)
{
	int index = iy * 3 + ix;//transforms cell matrix coordinate to integer index
	return GetCellState(index);
}

void Game::DoAIMoveRand()
{
	int filled_cell_counter=0;
	for (int index = 0; index < 9; index++) {// this 
		if (GetCellState(index) == CHILI) {
			filled_cell_counter++;
		}
	}
	if (filled_cell_counter == 0) {
		ChiliMoveX = rand() % 3; // makes the remainder of division stay between 0 and 2
		ChiliMoveY = rand() % 3;
		SetCellState(ChiliMoveX, ChiliMoveY, CHILI);
	}
}
void Game::DoUserInput() {
	if (!keysPressedLastFrame) {
		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			keysPressedLastFrame = true;
			hammerx++;
			if (hammerx>2) hammerx = 2;
		}

		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			keysPressedLastFrame = true;
			hammerx--;
			if (hammerx<0) hammerx = 0;
		}

		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			keysPressedLastFrame = true;
			hammery++;
			if (hammery>2) hammery = 2;
		}

		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			keysPressedLastFrame = true;
			hammery--;
			if (hammery<0) hammery = 0;
		}
		if (wnd.kbd.KeyIsPressed(VK_SPACE) ) {
			keysPressedLastFrame = true;
			if (!slampl) {//plays hammer slam
				slam.Play(1.0,0.2);
				slampl = true;
			}
		}
		
		if (wnd.kbd.KeyIsPressed(VK_SPACE) && GetCellState(hammerx, hammery) == CHILI) {
			keysPressedLastFrame = true;
			SetCellState(hammerx, hammery, EMPTY);
			chilicounter++;
		}
	}
	else if (!(wnd.kbd.KeyIsPressed(VK_RIGHT) || wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed(VK_DOWN) || wnd.kbd.KeyIsPressed(VK_UP)||wnd.kbd.KeyIsPressed(VK_SPACE))) {//if non of the keys are pressed
		keysPressedLastFrame = false;
		slampl = false;
	}
	
}*/
/*-------------------------------------------------------------------------*/
void Game::UpdateModel()
{
	while (!wnd.mouse.IsEmpty())
	{
		const auto e = wnd.mouse.Read();
		if (state == State::Memesweeper)
		{
		}
		else
		{
			if (!fieldcreated) {
				const SelectionMenu::Size s = menu.ProcessMouse(e);
				switch (s)
				{
				case SelectionMenu::Size::Small:
					CreateField(1, 1, 20, Field::Mode::Classic, font);
					state = State::Memesweeper;
					fieldcreated = true;
					break;
				case SelectionMenu::Size::Medium:
					CreateField(3, 3, 24, Field::Mode::NumPad, font);
					state = State::Memesweeper;
					fieldcreated = true;
					break;
				case SelectionMenu::Size::Large:
					CreateField(3, 3, 24, Field::Mode::NumPad, font);
					state = State::Memesweeper;
					fieldcreated = true;
					break;
				}
			}
		}
	}
	marleRight.Update(ft.Mark());
	/*if (!savedonce) {
		db.Add("chili", 69);
		db.Add("me-", 402);
		db.Add("absolute garbage", 15);
		db.Save("highscores.dat");
		savedonce = true;
	}
	if (!loadedonce) {
		db.Load("highscores.dat");
		loadedonce = true;
	}*/
	/*-----------WELCOMESCREEN-------------------*/
	/*if (!intropl) {//plays intro
		sky.Play();
		intropl = true;
	}
	if (!keysPressedLastFrame) {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			start = true;
			keysPressedLastFrame = true;
		}
	}

	/*----------------------GAME-----------------------------*/
	/*if (start) {
		DoAIMoveRand();
		DoUserInput();
		if (!gotStarttime) {//checks if starttime is already saved
			start_t = (int)time(NULL);
			cond_t = start_t;
			gotStarttime = true;
		}
		curr_t = (int)time(NULL);
		if (curr_t - cond_t > 0 && curr_t - start_t <= 60) {// calculation for 60 sec
			timeline_length=timeline_length-13.33f;
			cond_t++;
		}
		if (timeline_length <= 400 && timeline_length > 200) {
			line_r = 255, line_g = 255, line_b = 0;//yellow
		}
		else if (timeline_length <= 200 && timeline_length > 75) {
			line_r = 255, line_g = 128, line_b = 0;//orange
		}
		else if (timeline_length <= 75 && timeline_length >= 0) {
			line_r = 255, line_g = 0, line_b = 0;//red
		}
		else {
			line_r = 128, line_g = 255, line_b = 0;//light green
		}
		if ((int)timeline_length == 0) {
			outro = true;
			gotStarttime = false;
			start = false;
		}
	}
	/*-------------OUTRO-----------------*/
	/*if (outro) {
		if (!gotStarttime) {//checks if starttime is already saved
			start_t = (int)time(NULL);
			cond_t = start_t;
			gotStarttime = true;
		}
		curr_t = (int)time(NULL);
		if (!chipl) {//plays outro
			chi.Play();
			chipl = true;
		}
		if (curr_t - cond_t > 0 && curr_t - start_t <= 3) {// calculation for 60 sec
			outrow=outrow+150;
			cond_t++;
		}
		if (curr_t - start_t == 3) {
			outro = false;//ends outro after 3 seconds
			end = true;
		}
	}
	*/
}
void Game::ComposeFrame()
{
	if (state == State::Memesweeper)
	{
		pField->Draw(gfx);
	}
	else
	{
		menu.Draw(gfx);
	}
	marleRight.Draw({ wnd.mouse.GetPosX(), wnd.mouse.GetPosY() }, gfx);
	//db.Print(gfx, { 100,100 }, font);
	/*--------------START SCREEN---------------------------*/
	/*if (!start&&!outro&&!end) {
		DrawWelcomeScreen();
	}
	/*------------------GAME-------------------------------*/
	/*else if (timeline_length > 0) {
		DrawGrid(400, 300, cellw, 3);
		DrawTimeline(timeline_length, 10, line_r, line_g, line_b);
		for (int iy = 0; iy < 3; iy++) { //loop through rows
			for (int ix = 0; ix < 3; ix++) {			//loop through columns
				if (GetCellState(ix, iy) == CHILI) {//only chili in cell
					DrawChili(baseX + ix*cellw, baseY + iy*cellw + 5, 100);
				}

			}
		}
		if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
			DrawHammer2(baseX + hammerx*cellw, baseY + hammery*cellw);
		}
		else {
			DrawHammer1(baseX + hammerx*cellw, baseY + hammery*cellw);
		}
		DrawNumber(650, 100);
	}
	else if(outro) {
		DrawChili(400, 300, outrow);
	}
	else if(end) {
		DrawEndScreen();
	}
	 
	*/
	
	
	
}





