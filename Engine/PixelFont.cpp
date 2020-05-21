#pragma once
#include "PixelFont.h"

/* PIXEL FONT FUNCTIONS------------------------------------------
----------------------------------------------------------------*/

 void PixelFont::DrawString(const Vei2& pos, const std::string& string, Graphics & gfx, const Color& c) const
 {
	 int x = pos.x;
	 int y = pos.y;
	 for (size_t i = 0; i < string.size(); i++) {
		 DrawCharacter(x, y, gfx, string[i],c);
		 x += 15;
	 }
 }

void PixelFont::DrawCharacter(int x,int y, Graphics& gfx,int char_case_nr, const Color& c) const
{
	switch (char_case_nr)//case numbers according to ascii
	{
	case 97: // A
		DrawBlock(gfx, x + 6, y, c);

		DrawBlock(gfx, x + 3, y + 3, c);
		DrawBlock(gfx, x + 9, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 3, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 98: // B	
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 99: //C
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 100: //D
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 9, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 9, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		break;
	case 101: //E
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 102: //F
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		break;
	case 103: //G
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 104://H
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 105: //I
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x + 6, y + 3, c);

		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 6, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 106: //J
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x + 6, y + 3, c);

		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 6, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		break;
	case 107: //K
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 9, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 9, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 108: //L
		DrawBlock(gfx, x, y, c);

		DrawBlock(gfx, x, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 109: //M
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 3, y + 3, c);
		DrawBlock(gfx, x + 9, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 110: //N
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 3, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 111: //O
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 112: //P
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		break;
	case 113: //Q
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 9, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 114: //R
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 115: //S
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);

		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 116: //T
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x + 6, y + 3, c);

		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 6, y + 12, c);

		DrawBlock(gfx, x + 6, y + 15, c);
		break;
	case 117: //U
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 118: //V
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x + 3, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);

		DrawBlock(gfx, x + 3, y + 12, c);
		DrawBlock(gfx, x + 9, y + 12, c);

		DrawBlock(gfx, x + 6, y + 15, c);
		break;
	case 119: //W
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 6, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 120: // X
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x + 3, y + 3, c);
		DrawBlock(gfx, x + 9, y + 3, c);

		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 3, y + 12, c);
		DrawBlock(gfx, x + 9, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 121: //Y
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 6, y + 12, c);

		DrawBlock(gfx, x + 6, y + 15, c);
		break;
	case 122: //Z
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 3, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 48: // 0
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 9, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 3, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 49: // 1
		DrawBlock(gfx, x + 6, y, c);

		DrawBlock(gfx, x + 3, y + 3, c);
		DrawBlock(gfx, x + 6, y + 3, c);

		DrawBlock(gfx, x + 6, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 6, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 50: //2
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x + 3, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		DrawBlock(gfx, x + 12, y + 15, c);
		break;
	case 51: //3
		DrawBlock(gfx, x, y + 3, c);

		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x + 12, y + 12, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 52: // 4
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x + 6, y + 3, c);
		DrawBlock(gfx, x + 9, y + 3, c);

		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 3, y + 12, c);
		DrawBlock(gfx, x + 6, y + 12, c);
		DrawBlock(gfx, x + 9, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 53: // 5
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);


		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 54: // 6
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x + 3, y + 3, c);


		DrawBlock(gfx, x, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 3, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 55: // 7
		DrawBlock(gfx, x, y, c);
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);
		DrawBlock(gfx, x + 12, y, c);

		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 3, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		break;
	case 56: // 8
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 3, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 9, y + 15, c);
		break;
	case 57: // 9
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 3, y + 9, c);
		DrawBlock(gfx, x + 6, y + 9, c);
		DrawBlock(gfx, x + 9, y + 9, c);
		DrawBlock(gfx, x + 12, y + 6, c);

		DrawBlock(gfx, x + 12, y + 9, c);

		DrawBlock(gfx, x + 12, y + 12, c);

		DrawBlock(gfx, x + 9, y + 15, c);
		DrawBlock(gfx, x + 6, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		break;
	case 46: // .
		DrawBlock(gfx, x, y + 12, c);
		DrawBlock(gfx, x + 3, y + 12, c);
		DrawBlock(gfx, x, y + 15, c);
		DrawBlock(gfx, x + 3, y + 15, c);
		break;
	case 44: // ,
		DrawBlock(gfx, x, y + 9, c);
		DrawBlock(gfx, x + 3, y + 9, c);
		DrawBlock(gfx, x + 3, y + 12, c);
		DrawBlock(gfx, x, y + 15, c);
		break;
	case 39: // '
		DrawBlock(gfx, x, y, c);

		DrawBlock(gfx, x, y + 3, c);
		break;
	case 33: // !
		DrawBlock(gfx, x, y, c);

		DrawBlock(gfx, x, y + 3, c);

		DrawBlock(gfx, x, y + 6, c);

		DrawBlock(gfx, x, y + 9, c);

		DrawBlock(gfx, x, y + 15, c);
		break;
	case 45: // -
		DrawBlock(gfx, x, y + 6, c);
		DrawBlock(gfx, x + 3, y + 6, c);
		DrawBlock(gfx, x + 6, y + 6, c);
		break;
	case 63: // ?
		DrawBlock(gfx, x + 3, y, c);
		DrawBlock(gfx, x + 6, y, c);
		DrawBlock(gfx, x + 9, y, c);

		DrawBlock(gfx, x, y + 3, c);
		DrawBlock(gfx, x + 12, y + 3, c);

		DrawBlock(gfx, x + 9, y + 6, c);

		DrawBlock(gfx, x + 6, y + 9, c);

		DrawBlock(gfx, x + 6, y + 15, c);
	default:
		break;
	}
}

void PixelFont::DrawBlock(Graphics& gfx,int x, int y, const Color& c)const
/* Draws square 3x3 pixel block which all the pixel font characters
are made of */
{
	for (int xPos = x; xPos <= (x + 1); xPos++)
	{
		for (int yPos = y; yPos <= (y + 1); yPos++)
		{
			gfx.PutPixel(xPos, yPos, c);
		}
	}
}

