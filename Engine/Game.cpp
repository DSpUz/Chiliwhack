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
	menu({ gfx.GetScreenRect().GetCenter().x,300 },font),
	timeline(0,Graphics::ScreenWidth,0,10),
	tcol(Colors::Green),
	//hammer({400,300},Hammer::hammerState::StillUp),
	line_r(0),
	line_g(255),
	line_right(800.0f),
	chili_t(L"chili_t.wav"),
	slam(L"slam.wav"),
	chi(L"chi.wav")
{
	srand((unsigned int)time(NULL));//converts computer time since 1970 in a number and "seeds" random function
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

void Game::ResetTimeline()
{
	line_g = 255.0f;
	line_r = 0.0f;
	timeline.right = 800;
	line_right = 800.0f;
	tcol.SetR(unsigned char(line_r));
	tcol.SetG(unsigned char(line_g));
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
	const float dt = ft.Mark();
	if (!savedonce) {
		db.Add("chili", 69);
		db.Add("me-", 402);
		db.Add("absolute garbage", 15);
		db.Save("highscores.dat");
		savedonce = true;
	}
	if (!loadedonce) {
		db.Load("highscores.dat");
		loadedonce = true;
	}
	
	switch (state) {
	case State::SelectionMenu:
	if (!intropl) {//plays intro
		chili_t.Play();
		intropl = true;
	}
	if (!fieldcreated) {
		//hammer.UpdateHammer(dt, e, wnd.mouse.IsEmpty());
		mode = menu.ProcessMouse(wnd.mouse.Read(), SelectionMenu::Menutype::StartMenu,dt);
		switch (mode)
		{
		case SelectionMenu::Gamemode::Classic:
			CreateField(3, 3, 40, Field::Mode::Classic, font);
			state = State::Game;
			fieldcreated = true;
			break;
		case SelectionMenu::Gamemode::Mouse:
			CreateField(3, 3, 40, Field::Mode::Classic, font);
			state = State::Game;
			fieldcreated = true;
			break;
		case SelectionMenu::Gamemode::NumberPad:
			CreateField(3, 3, 40, Field::Mode::NumPad, font);
			state = State::Game;
			fieldcreated = true;

			break;
		default:
			break;
		}
	}
	else timer = 0.0f;
		break;
	case State::Game:
		if (timer<gametime) {
			//hammer.UpdateHammer(dt, wnd.mouse.Read(), wnd.mouse.IsEmpty());
			if(timer<gametime/2){
				line_r += colorscaling * 2 * dt;
				tcol.SetR(unsigned char(line_r));
			}
			else {
				line_g -= colorscaling * 2 * dt;
				tcol.SetG(unsigned char(line_g));
			}
			line_right-= Graphics::ScreenWidth / gametime * dt;
			timeline.right = int(line_right);
			switch (mode) {
			case SelectionMenu::Gamemode::Classic:
				pField->KeyboardInput(wnd.kbd.ReadKey(), dt, wnd.kbd.KeyIsEmpty());
				break;
			case SelectionMenu::Gamemode::Mouse:
				break;
			case SelectionMenu::Gamemode::NumberPad:
				pField->NumPadInput(wnd.kbd.ReadKey());
				break;
			}
			timer += dt;
		}
		else {
			state = State::BerserkerChili;
			timer = 0.0f;
			ResetTimeline();
	
		}
	break;
	case State::BerserkerChili:
		if (!outroonce) {
			if (!chipl) {
				chi.Play();
				chipl = true;
			}
			if (timer < 3.0f) {

				chiliwidth += int(150*dt);
				timer += dt;
			}
			else {
				state = State::HighscoreTable;
				timer = 0.0f;
				outroonce = true;
			}
		}
		else {
			state = State::HighscoreTable;
		}
		DestroyField();
		fieldcreated = false;
		break;
	case State::HighscoreTable:
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			state = State::Endscreen;
		}
		break;
	case State::Endscreen:
			mode = menu.ProcessMouse(wnd.mouse.Read(), SelectionMenu::Menutype::EndMenu,dt);
			switch (mode){
				case SelectionMenu::Gamemode::Replay:
					state = State::SelectionMenu;
					break;
				case SelectionMenu::Gamemode::Exit:
					wnd.Kill();
					break;
					}
		break;
	}
}
void Game::ComposeFrame()
{
	switch (state) {
	case State::SelectionMenu:
		gfx.DrawRect(timeline, tcol);
		font.DrawString({ Graphics::ScreenWidth / 3,Graphics::ScreenHeight / 6 }, "chiliwhack", gfx, 4, Colors::Green);
		menu.Draw(gfx, SelectionMenu::Menutype::StartMenu);
		//hammer.DrawHammer(gfx);
		break;
	case State::Game:
		gfx.DrawRect(timeline, tcol);
		switch (mode) {
		case SelectionMenu::Gamemode::Classic:
			pField->Draw(gfx);
			break;
		case SelectionMenu::Gamemode::Mouse:
			pField->Draw(gfx);
			//hammer.DrawHammer(gfx);
			break;
		case SelectionMenu::Gamemode::NumberPad:
			pField->Draw(gfx);
			break;
		}
		break;
	case State::BerserkerChili:
		if (!outroonce) {
			SpriteCodex::DrawChili({ Graphics::ScreenWidth / 2,Graphics::ScreenHeight / 2 }, chiliwidth, gfx);
		}
		break;
	case State::HighscoreTable:

		db.Print(gfx, { 100,100 }, font);
		break;
	case State::Endscreen:
		menu.Draw(gfx, SelectionMenu::Menutype::EndMenu);
		break;
	}
}





