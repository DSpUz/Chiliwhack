#pragma once
#include "Vei2.h"
#include "Animation.h"
#include "Mouse.h"
#include "Sound.h"
#include "Keyboard.h"

class Hammer {
public:
	enum class hammerState {
		StillUp,
		LeftIsPressed,
		LeftReleased,
		StillDown
	};
	Hammer(Vei2 in_pos, hammerState in_state);
	void SetPos(const Vei2& changepos);
	Vei2 GetPos() const;
	bool IsHammerPressed() const;
	void MouseUpdate(float dt, const Mouse::Event& e,bool MouseIsEmpty);
	void KeyboardUpdate(float dt,const Keyboard::Event& e, bool noinput,const int cellwidth);
	void DrawHammer(Graphics& gfx) const;
	void SilenceHammer();
private:
	float timer = 0.0f;
	bool pressedonce=false;
	Surface surf = Surface("hammer240x170.bmp");
	static constexpr float frametime = 0.01f;
	Animation hammerdown = Animation({ 0,0 }, 240, 170, 8, surf, frametime, false, Colors::Magenta);
		//hammerup = Animation({ 0,0 }, 240, 170, 8, surf, frametime, true, Colors::Magenta);
	Vei2 pos;
	hammerState state;
	Sound hammerslam = { L"slam.wav" };

};