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
	gfx(wnd)
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



/*-------------------------------------------------------------------------*/
/*GRAPHICS FUNCTIONS*/
/*void Game::DrawChili(int x, int y, int w)
{
	int cx = x, cy = y, width = w;

	float inc = 1; // triangle steepness counter

	for (int x = 0; x <= width / 8.0; x++) //top of the crown
	{
		for (int y = 0; y<inc; y++)
		{
			gfx.PutPixel(cx + x - width / 8.0f, cy - y - width * 7 / 16.0f, 0, 255, 0);
			gfx.PutPixel(cx + x - width / 4.0f, cy - y - width * 7 / 16.0f, 0, 255, 0);
			gfx.PutPixel(cx + x - width * 3 / 8.0f, cy - y - width * 7 / 16.0f, 0, 255, 0);
			gfx.PutPixel(cx + x - width / 2.0f, cy - y - width * 7 / 16.0f, 0, 255, 0);//first triangle spike from left

			gfx.PutPixel(cx - x + width / 8.0f, cy - y - width * 7 / 16.0f, 0, 255, 0); //right side mirrored cause of -x
			gfx.PutPixel(cx - x + width / 4.0f, cy - y - width * 7 / 16.0f, 0, 255, 0);
			gfx.PutPixel(cx - x + width * 3 / 8.0f, cy - y - width * 7 / 16.0f, 0, 255, 0);
			gfx.PutPixel(cx - x + width / 2.0f, cy - y - width * 7 / 16.0f, 0, 255, 0);
		}
		inc = inc + 2; //triangles are 2 times higher than wide
	}

	for (int x = 0; x <= width; x++) { // base of the crown (green rectangle)
		for (int y = 0; y <= width / 8.0f; y++) {
			gfx.PutPixel(cx + x - width / 2.0f, cy + y - width * 7 / 16.0f, 0, 255, 0);
		}
	}

	for (int x = 0; x <= width; x++) {//middle of face (white rectangle)
		for (int y = 0; y <= width / 2.0f; y++) {
			gfx.PutPixel(cx + x - width / 2.0, cy + y - width * 5 / 16.0, 255, 255, 255);
		}
	}

	inc = 1;
	for (int x = 0; x <= width / 2.0; x++) // white triangle chin
	{
		for (int y = 0; y<inc; y++)
		{
			gfx.PutPixel(cx + x - width / 2.0f, cy + y + width * 3 / 16.0f, 255, 255, 255); //left side
			gfx.PutPixel(cx - x + width / 2.0f, cy + y + width * 3 / 16.0f, 255, 255, 255);//right side
		}
		inc = inc + 0.85f;
	}

	for (int x = 0; x <= width / 4.0f; x++) { //black rectangle eyes
		for (int y = 0; y < width / 10.0f; y++) {
			gfx.PutPixel(cx + x + width / 16.0f, cy + y - width / 8.0f, 0, 0, 0); // right eye
			gfx.PutPixel(cx - x - width / 16.0f, cy + y - width / 8.0f, 0, 0, 0); //left eye
		}
	}

	for (int x = 0; x <= width / 20.0f; x++) { //black rectangle beard
		for (int y = 0; y <= width * 6 / 25.0f; y++) {
			gfx.PutPixel(cx + x - width / 40.0f, cy + y + width * 3 / 8.0f, 0, 0, 0);
		}
	}

	for (int x = 1; x <= width * 7 / 20.0f; x++) { // black eyebrows
		for (int y = 1; y < width / 16.0f; y++) {
			gfx.PutPixel(cx + x - width * 3 / 8.0f, cy + y - width * 9 / 40.0f, 0, 0, 0); // left eyebrow
			gfx.PutPixel(cx + x + width / 40.0f, cy + y - width * 9 / 40.0f, 0, 0, 0); //right eyebrow
		}
	}

	for (int x = 0; x <= width / 2.0f; x++) { // beige lips
		for (int y = 0; y <= width / 20.0f; y++) {
			gfx.PutPixel(cx + x - width / 4.0f, cy + y + width * 5 / 16.0f, 255, 220, 220);
		}
	}

	inc = 1;

	for (int x = 0; x <= width * 3 / 16.0f; x++) //beige cheeks 
	{
		for (int y = 0; y<inc; y++)
		{
			gfx.PutPixel(cx + x - width / 2.0f, cy + y + width * 3 / 16.0f, 255, 240, 240); //left cheek
			gfx.PutPixel(cx - x + width / 2.0f, cy + y + width * 3 / 16.0f, 255, 240, 240); // right cheek
		}
		inc = inc + 0.85f;
	}


	inc = 1;

	for (int x = 1; x <= width * 5 / 16.0f; x++)//beige nose  - nose height 
	{
		for (int y = 0; y<inc; y++)
		{
			gfx.PutPixel(cx + y, cy + x - width / 8.0f, 255, 240, 240);//right side
			gfx.PutPixel(cx - y, cy + x - width / 8.0f, 255, 240, 240);//left side
		}
		inc = inc + 0.5f;
	}



	for (int x = 0; x <= width / 4.0f; x++) { //black moustache-squares
		for (int y = 1; y < width * 3 / 80.0f; y++) {
			gfx.PutPixel(cx + x - width * 5 / 16.0f, cy + y + width / 4.0f, 0, 0, 0);
			gfx.PutPixel(cx + x + width / 16.0f, cy + y + width / 4.0f, 0, 0, 0);
		}
	}

	inc = 1;

	for (int x = 0; x <= width / 10.0f; x++)//black moustache triangles
	{
		for (int y = 0; y<inc; y++)
		{
			gfx.PutPixel(cx + y + width / 40.0f, cy + x + width * 3 / 16.0f, 0, 0, 0);
			gfx.PutPixel(cx - y - width / 40.0f, cy + x + width * 3 / 16.0f, 0, 0, 0);
		}
		inc = inc + 0.85f;
	}

}
void Game::DrawCell(int cellx, int celly, int sq_w, int line_g, int r, int g, int b)
{
	/*  cellx, celly - center coordinates of the star(see drawing)
	sq_w  -  cell width/2
	line_g -line gap(see drawing) */
/*
	int movex, movey;

	movey = celly;
	for (movex = cellx - sq_w; movex <= cellx; movex = movex + line_g) //3rd quadrant
	{
		gfx.DrawLine(cellx - sq_w, movey, movex, celly + sq_w, r, g, b); // x1,y1(start point of the line) x2,y2(end point of the line),red,green,blue from the draw-line function
		movey = movey + line_g;
	}

	movey = celly;
	for (movex = cellx + sq_w; movex >= cellx; movex = movex - line_g)
	{
		gfx.DrawLine(cellx + sq_w, movey, movex, celly + sq_w, r, g, b); //4th quadrant
		movey = movey + line_g;
	}

	movey = celly;
	for (movex = cellx + sq_w; movex >= cellx; movex = movex - line_g) //1st quadrant
	{
		gfx.DrawLine(cellx + sq_w, movey, movex, celly - sq_w, r, g, b);
		movey = movey - line_g;
	}

	movey = celly;
	for (movex = cellx - sq_w; movex <= cellx; movex = movex + line_g)
	{
		gfx.DrawLine(cellx - sq_w, movey, movex, celly - sq_w, r, g, b); //2nd quadrant
		movey = movey - line_g;
	}
}
void Game::DrawGrid(int posx, int posy,int cw,int rownumber)
{
	const int x = posx- rownumber*cw/2, y = posy- rownumber*cw/2; //upper left corner coordinates 
	const int cw2 = cw/2;// half of cell width
	int loopy = y + cw2; // initializes y-axis variable and sets it back to upper side of the square when both loops end


	while (loopy <= y + rownumber*cw)// comparison with the bottom side of the square(see the drawing)
	{
		int loopx = x + cw2; // initializes x-axis variable and sets it back to left side of the square when inner loop ends

		while (loopx < x + rownumber*cw)
		{
			DrawCell(loopx, loopy,cw2, 4, 102, 178, 255);
			loopx = loopx +  cw;
		}
		loopy = loopy + cw;
	}
}
void Game::DrawTimeline(int length, int height, int r,int g, int b)
{
	int x1 = 0,x2=length;
	for (int y = 0; y <= height; y++) {
		gfx.DrawLine(x1, y, x2-1, y, r, g, b);
}
}
void Game::DrawHammer1(int head_x, int head_y)
{
	gfx.DrawRectangle(head_x+85, head_y-15, 30, 150, 45, 118, 0, 0);
	gfx.DrawRectangle(head_x + 64, head_y -71, 20, 40, 45, 118, 0, 0);
	gfx.DrawRectangle(head_x +29, head_y-36 , 20, 40, 45, 118, 0, 0);

}
void Game::DrawHammer2(int head_x, int head_y)
{
	gfx.DrawRectangle(head_x + 80, head_y - 10, 30, 150, 20, 118, 0, 0);
	gfx.DrawRectangle(head_x + 36, head_y - 49, 20, 40, 20, 118, 0, 0);
	gfx.DrawRectangle(head_x + 20, head_y -5    , 20, 40, 20, 118, 0, 0);
}
void Game::DrawWelcomeScreen()
{
	font.DrawString({ 80,50 }, welcometext, gfx,3,Colors::Green);
	DrawTimeline(gfx.ScreenWidth, 10, 128, 255, 0);
	int x = 190, y = 240;
	DrawGrid(x, y, 40, 3);
	x = x + 200;
	DrawChili(x, y, 60);
	x = x + 150;
	DrawHammer1(x, y);
	/*----------------------------------
	---------THIRD ROW----------------*/
	/*x = 120, y = 400;
	int r = 0, g = 128, b = 0;
	gfx.chP(x, y, r, g, b); x = x + 30; gfx.chR(x, y, r, g, b); x = x + 30; gfx.chE(x, y, r, g, b); x = x + 30;
	gfx.chS(x, y, r, g, b); x = x + 30; gfx.chS(x, y, r, g, b); //press
	x = x + 45;
	gfx.chE(x, y, r, g, b); x = x + 30; gfx.chN(x, y, r, g, b); x = x + 30; gfx.chT(x, y, r, g, b); x = x + 30;
	gfx.chE(x, y, r, g, b); x = x + 30; gfx.chR(x, y, r, g, b);//enter
	x = x + 45;
	gfx.chT(x, y, r, g, b); x = x + 30; gfx.chO(x, y, r, g, b);//to
	x = x + 45;
	gfx.chS(x, y, r, g, b); x = x + 30; gfx.chT(x, y, r, g, b); x = x + 30; gfx.chA(x, y, r, g, b); x = x + 30;
	gfx.chR(x, y, r, g, b); x = x + 30; gfx.chT(x, y, r, g, b); x = x + 30; gfx.chPoint(x, y, r, g, b); x = x + 10;
	gfx.chPoint(x, y, r, g, b); x = x + 10;//start..
}
void Game::DrawDigit(int index, int x, int y)
{
	switch (index)  //sets chosen cell to empty or chili
	{
	case 0:
		gfx.ch0(x, y, 0, 146, 14);
		break;
	case 1:
		gfx.ch1(x, y, 0, 146, 14);
		break;
	case 2:
		gfx.ch2(x, y, 0, 146, 14);
		break;
	case 3:
		gfx.ch3(x, y, 0, 146, 14);
		break;
	case 4:
		gfx.ch4(x, y, 0, 146, 14);
		break;
	case 5:
		gfx.ch5(x, y, 0, 146, 14);
		break;
	case 6:
		gfx.ch6(x, y, 0, 146, 14);
		break;
	case 7:
		gfx.ch7(x, y, 0, 146, 14);
		break;
	case 8:
		gfx.ch8(x, y, 0, 146, 14);
		break;
	case 9:
		gfx.ch9(x, y, 0, 146, 14);
		break;
	default:
		break;
	}
}
void Game::DrawNumber(int x, int y)
{
	int hor = x, ver = y;
	int hundred, ten, dig, rest;// digits of hundreds, tens and rest
	hundred = chilicounter / 100; rest = chilicounter % 100;
	if (hundred > 0) {
		DrawDigit(hundred, hor, ver); //prints hundred digit
		hor = hor + 30;
	}
	ten = rest / 10; dig = rest % 10;
	if (hundred > 0) {
		DrawDigit(ten, hor, ver);
		hor = hor + 30;
	}
	else if (ten > 0) {
		DrawDigit(ten, hor, ver);
		hor = hor + 30;
	}
	DrawDigit(dig, hor, ver);//prints last digit

}
void Game::DrawEndScreen()
{
	int x = 150, y = 100;
	int r = 0, g = 146, b = 14;
	/*---------FIRST ROW--------------*//*
	gfx.chC(x, y, r, g, b); x = x + 30; gfx.chO(x, y, r, g, b); x = x + 30; gfx.chN(x, y, r, g, b); x = x + 30;
	gfx.chG(x, y, r, g, b); x = x + 30; gfx.chR(x, y, r, g, b); x = x + 30; gfx.chA(x, y, r, g, b); x = x + 30;
	gfx.chT(x, y, r, g, b); x = x + 30; gfx.chU(x, y, r, g, b); x = x + 30; gfx.chL(x, y, r, g, b); x = x + 30;
	gfx.chA(x, y, r, g, b); x = x + 30; gfx.chT(x, y, r, g, b); x = x + 30; gfx.chI(x, y, r, g, b); x = x + 10;
	gfx.chO(x, y, r, g, b); x = x + 30; gfx.chN(x, y, r, g, b); x = x + 30; gfx.chS(x, y, r, g, b); x = x + 30;
	gfx.chExMark(x, y, r, g, b);//Congratulations!
	 /*----------------------------------
	 ---------SECOND ROW----------------*/
	/*x = 140, y = 400;
	gfx.chY(x, y, r, g, b); x = x + 30; gfx.chO(x, y, r, g, b); x = x + 30; gfx.chU(x, y, r, g, b); //you
	x = x + 45;
	gfx.chG(x, y, r, g, b); x = x + 30; gfx.chO(x, y, r, g, b); x = x + 30; gfx.chT(x, y, r, g, b);//got
	x = x + 45;
	DrawNumber(x, y);
	if (chilicounter > 99) {
		x = x + 105;
	}
	else if(chilicounter > 9){
		x = x + 75;
	}
	else x = x + 45;
	
	gfx.chC(x, y, r, g, b); x = x + 30; gfx.chH(x, y, r, g, b); x = x + 30; gfx.chI(x, y, r, g, b); x = x + 10;
	gfx.chL(x, y, r, g, b); x = x + 30; gfx.chI(x, y, r, g, b); x = x + 10; gfx.chApostrophe(x, y, r, g, b); x = x + 10;
	gfx.chS(x, y, r, g, b);//Chili's
}
/*-------------------------------------------------------------------------*/

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





