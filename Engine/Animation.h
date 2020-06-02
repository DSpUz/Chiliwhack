#pragma once
#include "Surface.h"
#include "Graphics.h"
#include <vector>
class Animation {
public:
	Animation(const Vei2& startpos, int width, int height, int numFrames, const Surface& sprite, float htime,bool reverse, const Color& colkey);
	void Draw(const Vei2& pos, Graphics& gfx) const;
	void Draw(const Vei2& pos, Graphics& gfx,const RectI& clip) const;
	void Update(float dt);
private:
	void Advance();
private:
	Color colorkey;
	const Surface& spritesheet;
	std::vector<RectI> frames;
	int frameIndex=0;
	float holdTime;//how long should frames hold
	float curFrameTime=0.0f;

};