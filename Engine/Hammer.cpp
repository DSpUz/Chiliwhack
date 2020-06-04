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

void Hammer::UpdateHammer(float dt, const Mouse::Event & e)
{

	if (timer < 16 * frametime) {
		timer += dt;
		if (timer < 8 * frametime) {
			if (state == hammerState::LeftIsPressed) {
				SetPos(e.GetPos());
				hammerdown.Update(dt);
			}
			else {
				switch (e.GetType())
				{
				case Mouse::Event::Type::Move:
					state = hammerState::StillUp;
					SetPos(e.GetPos());
					break;
				case Mouse::Event::Type::LPress:
					SetPos(e.GetPos());
					hammerdown.Update(dt);
					state = hammerState::LeftIsPressed;
					break;
				}
			}
		}
		else {
			if (state == hammerState::LeftIsPressed) {
				switch (e.GetType())
				{
				case Mouse::Event::Type::Move:
					state = hammerState::LeftReleased;
					hammerup.Update(dt);
					SetPos(e.GetPos());
					break;
				case Mouse::Event::Type::LPress:
					SetPos(e.GetPos());
					state = hammerState::StillDown;
					break;
				}
			}
			else {
				switch (e.GetType())
				{
				case Mouse::Event::Type::Move:
					hammerup.Update(dt);
					SetPos(e.GetPos());
					break;
				case Mouse::Event::Type::LPress:
					timer = 0.0f;
					SetPos(e.GetPos());
					state = hammerState::LeftIsPressed;
					break;
				}
			}
		}
	}
	else {
		switch (e.GetType())
		{
		case Mouse::Event::Type::Move:
			timer = 0.0f;
			state = hammerState::StillUp;
			SetPos(e.GetPos());
			break;
		case Mouse::Event::Type::LPress:
			timer = 0.0f;
			state = hammerState::LeftIsPressed;
			break;
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
		gfx.DrawSprite(pos.x, pos.y, { 0,240,0,140 }, gfx.GetScreenRect(), surf, Colors::Magenta);
		break;
	case hammerState::StillDown:
		gfx.DrawSprite(pos.x, pos.y, { 1680,1920,0,140 }, gfx.GetScreenRect(), surf, Colors::Magenta);
		break;
	default:
		break;
	}
}
