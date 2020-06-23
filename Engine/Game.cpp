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

void Game::readplayername(const Keyboard::Event & e, char*& playername,int& charcounter)
{
	*playername = 0;
		if (e.IsPress()) {
			int charcode = int(e.GetCode());
			if (charcounter < sizeof(namebuffer)&&charcounter>=0){
				if (charcode == 8) {
					if (charcounter != 0)  {
						*playername = 0;
						playername--;
						charcounter--;
						*playername = 0;
					}
				}
				else {
					if (charcode > 64 && charcode < 91) {
						charcode += 32;
						*playername = char(charcode);
						playername++;	
						*playername = 0;
					}
					else {
						*playername = e.GetCode();
						playername++;
						*playername = 0;
					}
					charcounter++;
				}
			}
			else {
				if (charcode == 8) {
				playername = &namebuffer[sizeof(namebuffer)];
				*playername = 0;
				playername--;
				*playername = 0;
				charcounter--;
				}
			}
		}
}







//slam.Play(1.0,0.2);
	
void Game::UpdateModel()
{
	const float dt = ft.Mark();
	
	switch (state) {
	case State::SelectionMenu:
	if (!intropl) {//plays intro
		chili_t.Play();
		intropl = true;
	}
	if (!fieldcreated) {
		mode = menu.ProcessMouse(wnd.mouse.Read(), SelectionMenu::Menutype::StartMenu,dt);
		switch (mode)
		{
		case SelectionMenu::Gamemode::Classic:
			CreateField(3, 3, 72, Field::Mode::Classic, font);
			modeplayed = Field::Mode::Classic;
			state = State::Game;
			fieldcreated = true;
			break;
		case SelectionMenu::Gamemode::Mouse:
			CreateField(3, 3, 72, Field::Mode::Classic, font);
			modeplayed = Field::Mode::Mouse;
			state = State::Game;
			fieldcreated = true;
			break;
		case SelectionMenu::Gamemode::NumberPad:
			CreateField(3, 3, 72, Field::Mode::NumPad, font);
			modeplayed = Field::Mode::NumPad;
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
				pField->KeyboardInput(wnd.kbd.ReadKey(), dt, wnd.kbd.KeyIsEmpty(), chilicounter);
				break;
			case SelectionMenu::Gamemode::Mouse:
				pField->MouseInput(wnd.mouse.Read(), dt, wnd.mouse.IsEmpty(), chilicounter);
				break;
			case SelectionMenu::Gamemode::NumberPad:
				pField->NumPadInput(wnd.kbd.ReadKey(), chilicounter);
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
		readplayername(wnd.kbd.ReadKey(), namepointer, curNameSize);
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			state = State::Endscreen;
		}
		break;
	case State::Endscreen:
		if (!savedonce) {
			if (db.CheckIfHighscore(chilicounter, modeplayed)) {
				db.Add(namebuffer, chilicounter, modeplayed);
			}
			db.Save("highscores.dat");
			savedonce = true;
		}
		if (!loadedonce) {
			db.Load("highscores.dat");
			loadedonce = true;
		}
			mode = menu.ProcessMouse(wnd.mouse.Read(), SelectionMenu::Menutype::EndMenu,dt);
			switch (mode){
				case SelectionMenu::Gamemode::Replay:
					chilicounter = 0;
					savedonce = false;
					loadedonce = false;
					state = State::SelectionMenu;
					break;
				case SelectionMenu::Gamemode::Exit:
					menu.SilenceHammer();
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
		break;
	case State::Game:
		gfx.DrawRect(timeline, tcol);
		switch (mode) {
		case SelectionMenu::Gamemode::Classic:
			pField->Draw(gfx);
			font.DrawString({ 650,100 }, font.int2string(chilicounter), gfx, 4, { 0,122,0 });
			break;
		case SelectionMenu::Gamemode::Mouse:
			pField->Draw(gfx);
			font.DrawString({ 650,100 }, font.int2string(chilicounter), gfx, 4, { 0,122,0 });
			break;
		case SelectionMenu::Gamemode::NumberPad:
			pField->Draw(gfx);
			font.DrawString({ 650,100 }, font.int2string(chilicounter), gfx, 4, { 0,122,0 });
			break;
		}
		break;
	case State::BerserkerChili:
		if (!outroonce) {
			SpriteCodex::DrawChili({ Graphics::ScreenWidth / 2,Graphics::ScreenHeight / 2 }, chiliwidth, gfx);
		}
		break;
	case State::HighscoreTable:
		db.Print(gfx, { 100,100 }, font, modeplayed);
		font.DrawString({ 100,500 }, namebuffer, gfx, 2, Colors::Green);
		break;
	case State::Endscreen:
		db.Print(gfx, { 100,100 }, font, modeplayed);
		menu.Draw(gfx, SelectionMenu::Menutype::EndMenu);
		break;
	}
}





