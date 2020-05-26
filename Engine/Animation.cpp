#include "Animation.h"

Animation::Animation(const Vei2 & startpos, int width, int height, int numFrames, const Surface & sprite, float htime, const Color & colkey)
:
spritesheet(sprite),
holdTime(htime),
colorkey(colkey)
{
	for (int i = 0; i < numFrames; i++) {
		frames.emplace_back(startpos.x + i * width, startpos.x + (i + 1) * width, startpos.y, startpos.y + height);
	}
}

void Animation::Draw(const Vei2 & pos, Graphics & gfx) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[frameIndex],spritesheet, colorkey);
}

void Animation::Draw(const Vei2 & pos, Graphics & gfx, const RectI & clip) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[frameIndex],clip, spritesheet, colorkey);
}

void Animation::Update(float dt)
{
	curFrameTime += dt;
	while (curFrameTime >= holdTime) {
		Advance();
		curFrameTime -= holdTime;
	}
}

void Animation::Advance()
{
	if (++frameIndex >= frames.size()) {
		frameIndex = 0;
	}
}
