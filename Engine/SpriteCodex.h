#pragma once
#include "Graphics.h"
#include "Vei2.h"

class SpriteCodex
{
public:
	static void DrawChili(const Vei2& pos, int w, Graphics& gfx);
	static void DrawCell(const Vei2& pos, int sq_w, int line_g, int r, int g, int b, Graphics& gfx);
	static void DrawHammer1(const Vei2& pos, Graphics&gfx);
	static void DrawHammer2(const Vei2& pos, Graphics& gfx);
};