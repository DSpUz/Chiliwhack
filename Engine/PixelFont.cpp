#pragma once
#include "PixelFont.h"

/* PIXEL FONT FUNCTIONS------------------------------------------
----------------------------------------------------------------*/

void PixelFont::DrawString(const Vei2& pos, const std::string& string, Graphics & gfx,int fontsize, const Color& c) const
 {
	 int x = pos.x;
	 int y = pos.y;
	 const int padding = (fontsize + fontsize / 2)*6;
	 for (size_t i = 0; i < string.size(); i++) {
		 if (string[i] == 32) {//space
			 x += padding/2;
		 }
		 else if (string[i] == 105|| string[i] == 46 || string[i] == 39 || string[i] == 33 ) {// i .' or !
			 DrawCharacter(x, y, gfx, string[i], fontsize, c);
			 x += padding/3;
		 }
		 else if (string[i] == 49) {//1
			 DrawCharacter(x, y, gfx, string[i], fontsize, c);
			 x += padding *4/6;
		 }
		 else if (string[i] == 44) {//,
			 DrawCharacter(x, y, gfx, string[i], fontsize, c);
			 x += padding /2;
		 }
		 else {
			 DrawCharacter(x, y, gfx, string[i], fontsize, c);
			 x += padding;
		 }
	 }
 }

void PixelFont::DrawCharacter(int x,int y, Graphics& gfx,int char_case_nr,int fontsize, const Color& c) const
{
	const int xy1 = fontsize + fontsize / 2;
	const int xy2 = xy1 * 2;
	const int xy3 = xy1 * 3;
	const int xy4 = xy1 * 4;
	const int y5 = xy1 * 5;
	const int y6 = xy1 * 6;
	switch (char_case_nr)//case numbers according to ascii
	{
	case 97: // A
		DrawBlock(gfx, x + xy2, y,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 98: // B	
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 99: //C
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 100: //D
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		break;
	case 101: //E
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 102: //F
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		break;
	case 103: //G
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 104://H
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 105: //I
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x , y + xy1,fontsize,c);
		DrawBlock(gfx, x , y + xy2,fontsize,c);
		DrawBlock(gfx, x , y + xy3,fontsize,c);
		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x, y + y5,fontsize,c);	
		break;
	case 106: //J
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		break;
	case 107: //K
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 108: //L
		DrawBlock(gfx, x, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 109: //M
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 110: //N
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 111: //O
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 112: //P
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		break;
	case 113: //Q
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 114: //R
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 115: //S
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 116: //T
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		break;
	case 117: //U
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 118: //V
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		break;
	case 119: //W
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 120: // X
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 121: //Y
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		break;
	case 122: //Z
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 48: // 0
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 49: // 1
		DrawBlock(gfx, x + xy1, y,fontsize,c);

		DrawBlock(gfx, x , y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);

		DrawBlock(gfx, x , y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		break;
	case 50: //2
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy4, y + y5,fontsize,c);
		break;
	case 51: //3
		DrawBlock(gfx, x, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 52: // 4
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 53: // 5
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);


		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 54: // 6
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy1,fontsize,c);


		DrawBlock(gfx, x, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 55: // 7
		DrawBlock(gfx, x, y,fontsize,c);
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);
		DrawBlock(gfx, x + xy4, y,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		break;
	case 56: // 8
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		break;
	case 57: // 9
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy1, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy3, y + xy3,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy4, y + xy4,fontsize,c);

		DrawBlock(gfx, x + xy3, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		break;
	case 46: // .	
		DrawBlock(gfx, x, y + y5,fontsize,c);
		break;
	case 44: // ,
		DrawBlock(gfx, x, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy4,fontsize,c);
		DrawBlock(gfx, x + xy1, y + y5,fontsize,c);
		DrawBlock(gfx, x, y + y6,fontsize,c);
		break;
	case 39: // '
		DrawBlock(gfx, x, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		break;
	case 33: // !
		DrawBlock(gfx, x, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);

		DrawBlock(gfx, x, y + xy2,fontsize,c);

		DrawBlock(gfx, x, y + xy3,fontsize,c);

		DrawBlock(gfx, x, y + y5,fontsize,c);
		break;
	case 45: // -
		DrawBlock(gfx, x, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy1, y + xy2,fontsize,c);
		DrawBlock(gfx, x + xy2, y + xy2,fontsize,c);
		break;
	case 63: // ?
		DrawBlock(gfx, x + xy1, y,fontsize,c);
		DrawBlock(gfx, x + xy2, y,fontsize,c);
		DrawBlock(gfx, x + xy3, y,fontsize,c);

		DrawBlock(gfx, x, y + xy1,fontsize,c);
		DrawBlock(gfx, x + xy4, y + xy1,fontsize,c);

		DrawBlock(gfx, x + xy3, y + xy2,fontsize,c);

		DrawBlock(gfx, x + xy2, y + xy3,fontsize,c);

		DrawBlock(gfx, x + xy2, y + y5,fontsize,c);
	default:
		break;
	}
}

void PixelFont::DrawBlock(Graphics& gfx,int x, int y,int width, const Color& c)const
/* Draws square 3x3 pixel block which all the pixel font characters
are made of */
{
	for (int xPos = x; xPos < (x + width); xPos++)
	{
		for (int yPos = y; yPos < (y + width); yPos++)
		{
			gfx.PutPixel(xPos, yPos, c);
		}
	}
}

