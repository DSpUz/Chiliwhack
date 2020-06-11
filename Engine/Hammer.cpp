#include "Hammer.h"

Hammer::Hammer(Vei2 in_pos, hammerState in_state):
	pos(in_pos),
	state(in_state)
{
}

void Hammer::SetPos(const Vei2 & changepos)
{
	pos = changepos;
}

Vei2 Hammer::GetPos() const
{
	return pos;
}

float Hammer::GetTimer() const
{
	return timer;
}

float Hammer::GetFrameTime() const
{
	return frametime;
}

void Hammer::SetState(hammerState in_state)
{
	state = in_state;
}

void Hammer::MouseUpdate(float dt, const Mouse::Event & e,bool MouseIsEmpty)
{
if (MouseIsEmpty) {
	if (pressedonce) {
			timer += dt;
			if (timer >= 8 * frametime) {
				timer = 0.0f;
				hammerdown.ResetToFirstFrame();
				pressedonce = false;
			}
			else {
				hammerdown.Update(dt,timer);
			}
	}
}
else {
	SetPos(e.GetPos());
	if (pressedonce) {
		timer += dt;
		if (timer >= 8 * frametime) {
			hammerdown.ResetToFirstFrame();
			timer = 0.0f;
			pressedonce = false;
		}
		else {
		hammerdown.Update(dt, timer);
		}
	}
	else {
		switch (e.GetType())
		{
		case Mouse::Event::Type::LRelease:
			if (!pressedonce) {
				state = hammerState::StillUp;
			}
			break;
		case Mouse::Event::Type::LPress:
			state = hammerState::LeftIsPressed;
			hammerslam.Play();
			pressedonce = true;
			break;
		default:
			break;
		}
	}
}
}

void Hammer::UpdateTimer(float dt)
{ 
	timer += dt;
}

void Hammer::UpdateAnimation(float in_dt, float in_timer)
{
	hammerdown.Update(in_dt, in_timer);
}

void Hammer::ResetToFirstFrame()
{
	hammerdown.ResetToFirstFrame();
}

void Hammer::ResetTimer()
{
	timer = 0.0f;
}


void Hammer::DrawHammer(Graphics& gfx) const
{
	switch (state) {
	case hammerState::LeftIsPressed:
		hammerdown.Draw(pos - Vei2{0, 100}, gfx);
		break;
	//case hammerState::LeftReleased:
		//hammerup.Draw(pos - Vei2{ 0,100 }, gfx);
		//break;
	case hammerState::StillUp:
		gfx.DrawSprite(pos.x, pos.y-100, { 0,240,0,170 }, gfx.GetScreenRect(), surf, Colors::Magenta);
		break;
	//case hammerState::StillDown:
		//gfx.DrawSprite(pos.x, pos.y-100, { 1680,1920,0,170 }, gfx.GetScreenRect(), surf, Colors::Magenta);
		//break;
	default:
		break;
	}
}
