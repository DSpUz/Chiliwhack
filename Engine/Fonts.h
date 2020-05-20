#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Vei2.h"
/*Pixel font originally designed by forum member Nny:
https://forum.planetchili.net/viewtopic.php?f=3&t=3703 , updated by
me(krautersuppe) and (adapted)final version used here by DEM0N194*/
class PixelFont{
public:
	PixelFont(int in_x, int in_y, int char_nr, Color col);
	void DrawString(const Vei2& pos,const std::string& string, Graphics& gfx) const;
	void DrawCharacter(const Vei2& pos,Graphics& gfx,int char_case_nr) const;
	void DrawBlock(Graphics& gfx,int x,int y,Color c) const;
private:
	int x;
	int y;
	int char_case_nr;
	Color c;
};