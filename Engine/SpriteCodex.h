#pragma once
#include "Graphics.h"
#include "Vei2.h"

class SpriteCodex
{
public:
	static void DrawChili(const Vei2& pos, int w, Graphics& gfx);//x-coordinate, y- coordinate and width thanks to Legacy http://forum.planetchili.net/viewtopic.php?f=3&t=3890
	static void DrawCell(const Vei2& pos, int sq_w, int line_g, int r, int g, int b, Graphics& gfx);//Thanks to Asimov - see http://www.planetchili.net/forum/viewtopic.php?f=3&t=1065
};