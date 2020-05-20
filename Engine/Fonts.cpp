#pragma once
#include "Fonts.h"

/* PIXEL FONT FUNCTIONS------------------------------------------
----------------------------------------------------------------*/


 PixelFont::PixelFont(int in_x, int in_y, int char_nr, Color col)
	 :
 x (in_x),
 y (in_y),
 char_case_nr(char_nr),
 c (col)
{
}

 void PixelFont::DrawString(const Vei2& pos, const std::string & string, Graphics & gfx) const
 {
 }

void PixelFont::DrawCharacter(const Vei2& pos, Graphics& gfx,int char_case_nr) const
{
	switch (char_case_nr)//case numbers according to ascii
	{
	case 97: // A
		DrawBlock(gfx,pos.x + 6,pos.y, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 98: // B	
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 99: //C
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 100: //D
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		break;
	case 101: //E
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 102: //F
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		break;
	case 103: //G
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 104://H
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 105: //I
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 106: //J
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		break;
	case 107: //K
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 108: //L
		DrawBlock(gfx,pos.x,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 109: //M
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 110: //N
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 111: //O
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 112: //P
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		break;
	case 113: //Q
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 114: //R
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 115: //S
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 116: //T
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		break;
	case 117: //U
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 118: //V
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		break;
	case 119: //W
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 120: // X
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 121: //Y
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		break;
	case 122: //Z
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 48: // 0
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 49: // 1
		DrawBlock(gfx,pos.x + 6,pos.y, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 50: //2
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 15, c);
		break;
	case 51: //3
		DrawBlock(gfx,pos.x,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 52: // 4
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 53: // 5
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);


		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 54: // 6
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 3, c);


		DrawBlock(gfx,pos.x,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 55: // 7
		DrawBlock(gfx,pos.x,pos.y, c);
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);
		DrawBlock(gfx,pos.x + 12,pos.y, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		break;
	case 56: // 8
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		break;
	case 57: // 9
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 3,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 9,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 12,pos.y + 12, c);

		DrawBlock(gfx,pos.x + 9,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		break;
	case 46: // .
		DrawBlock(gfx,pos.x,pos.y + 12, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);
		DrawBlock(gfx,pos.x,pos.y + 15, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 15, c);
		break;
	case 44: // ,
		DrawBlock(gfx,pos.x,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 9, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 12, c);
		DrawBlock(gfx,pos.x,pos.y + 15, c);
		break;
	case 39: // '
		DrawBlock(gfx,pos.x,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		break;
	case 33: // !
		DrawBlock(gfx,pos.x,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);

		DrawBlock(gfx,pos.x,pos.y + 6, c);

		DrawBlock(gfx,pos.x,pos.y + 9, c);

		DrawBlock(gfx,pos.x,pos.y + 15, c);
		break;
	case 45: // -
		DrawBlock(gfx,pos.x,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 3,pos.y + 6, c);
		DrawBlock(gfx,pos.x + 6,pos.y + 6, c);
		break;
	case 63: // ?
		DrawBlock(gfx,pos.x + 3,pos.y, c);
		DrawBlock(gfx,pos.x + 6,pos.y, c);
		DrawBlock(gfx,pos.x + 9,pos.y, c);

		DrawBlock(gfx,pos.x,pos.y + 3, c);
		DrawBlock(gfx,pos.x + 12,pos.y + 3, c);

		DrawBlock(gfx,pos.x + 9,pos.y + 6, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 9, c);

		DrawBlock(gfx,pos.x + 6,pos.y + 15, c);
	default:
		break;
	}
}

void PixelFont::DrawBlock(Graphics& gfx,int x, int y, Color c)const
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

