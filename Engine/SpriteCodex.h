#pragma once

#include "Graphics.h"
#include "Vei2.h"

class SpriteCodex
{
public:
	// width and height of all tiles
	static constexpr int tileSize = 16;
	// base color for all tiles
	static constexpr Color baseColor = { 192,192,192 };
	// 16x16 tile sprites assume (192,192,192) background and top left origin
	static void DrawChili(const Vei2& pos, int w, Graphics& gfx);
	static void DrawCell(const Vei2& pos, int sq_w, int line_g, int r, int g, int b, Graphics& gfx);
	static void DrawHammer1(const Vei2& pos, Graphics&gfx);
	static void DrawHammer2(const Vei2& pos, Graphics& gfx);
	
	// Text for size selection (center origin)
	//
	static constexpr int sizeselWidth = 240;
	static constexpr int sizeselHeight = 56;
	static void DrawSmall( const Vei2& pos,Graphics& gfx );
	static void DrawMedium( const Vei2& pos,Graphics& gfx );
	static void DrawLarge( const Vei2& pos,Graphics& gfx );
};