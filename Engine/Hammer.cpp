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

bool Hammer::IsHammerPressed() const
{
	return pressedonce;
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

void Hammer::KeyboardUpdate(float dt, const Keyboard::Event & e,bool noinput, const int cellwidth)
{
	if (noinput) {
		if (pressedonce) {
			timer += dt;
			if (timer >= 8 * frametime) {
				timer = 0.0f;
				hammerdown.ResetToFirstFrame();
				pressedonce = false;
			}
			else {
				hammerdown.Update(dt, timer);
			}
		}
	}
	else {
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
		else if (e.IsPress()) {
			const int number = int(e.GetCode());
			switch (number)
			{
			case 32: //Space
			state = hammerState::LeftIsPressed;
			hammerslam.Play();;
			pressedonce = true;
			break;
			case VK_RIGHT:
				pos += {2*cellwidth, 0};
				break;
			case VK_LEFT:
				pos -= {2*cellwidth, 0};
				break;
			case VK_UP:
				pos -= {0,2*cellwidth};
				break;
			case VK_DOWN:	
				pos += {0, 2*cellwidth};
				break;
		
			}
		}
		
	}
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
