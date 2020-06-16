#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Vei2.h"
/*Pixel font originally designed by forum member Nny:
https://forum.planetchili.net/viewtopic.php?f=3&t=3703 , updated by
me(krautersuppe) and (adapted)final version used here by DEM0N194*/
struct PixelFont{
	void DrawString(const Vei2& pos,const std::string& string, Graphics& gfx,int fontsize,const Color& c) const;
	void DrawCharacter(int x, int y,Graphics& gfx,int char_case_nr,int fontsize,const Color& c) const;
	void DrawBlock(Graphics& gfx,int x,int y, int width,const Color& c) const;
	std::string int2string(int i) const;
};