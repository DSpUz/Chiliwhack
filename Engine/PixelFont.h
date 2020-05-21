#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Vei2.h"
/*Pixel font originally designed by forum member Nny:
https://forum.planetchili.net/viewtopic.php?f=3&t=3703 , updated by
me(krautersuppe) and (adapted)final version used here by DEM0N194*/
class PixelFont{
public:
	void DrawString(const Vei2& pos,const std::string& string, Graphics& gfx,const Color& c) const;
	void DrawCharacter(int x, int y,Graphics& gfx,int char_case_nr,const Color& c) const;
	void DrawBlock(Graphics& gfx,int x,int y,const Color& c) const;
};