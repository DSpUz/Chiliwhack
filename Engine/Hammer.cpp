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

void Hammer::UpdateHammer(float dt, const Mouse::Event & e,bool MouseIsEmpty)
{
	if (timer >= 8 * frametime) {
		timer = 0.0f;
		pressedonce = false;
	}

if (MouseIsEmpty) {
	if (pressedonce) {
		timer += dt;
		hammerdown.Update(dt);
	}
}
else {
	SetPos(e.GetPos());
	if (pressedonce) {
		timer += dt;
		hammerdown.Update(dt);
	}
	else {
		switch (e.GetType())
		{
		case Mouse::Event::Type::Move:
			state = hammerState::StillUp;
			break;
		case Mouse::Event::Type::LPress:
			state = hammerState::LeftIsPressed;
			pressedonce = true;
			break;
		default:
			break;
		}
	}
}
}


void Hammer::DrawHammer(Graphics& gfx) const
{
	switch (state) {
	case hammerState::LeftIsPressed:
		hammerdown.Draw(pos, gfx);
		break;
	case hammerState::LeftReleased:
		hammerup.Draw(pos, gfx);
		break;
	case hammerState::StillUp:
		gfx.DrawSprite(pos.x, pos.y, { 0,240,0,170 }, gfx.GetScreenRect(), surf, Colors::Magenta);
		break;
	case hammerState::StillDown:
		gfx.DrawSprite(pos.x, pos.y, { 1680,1920,0,170 }, gfx.GetScreenRect(), surf, Colors::Magenta);
		break;
	default:
		break;
	}
}
