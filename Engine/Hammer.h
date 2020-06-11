#pragma once
#include "Vei2.h"
#include "Animation.h"
#include "Mouse.h"
#include "Sound.h"

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
	float GetTimer() const;
	float GetFrameTime() const;
	void SetState(hammerState in_state);
	void MouseUpdate(float dt, const Mouse::Event& e,bool MouseIsEmpty);
	void UpdateTimer(float dt);
	void UpdateAnimation(float in_dt,float in_timer);
	void ResetToFirstFrame();
	void ResetTimer();
	void DrawHammer(Graphics& gfx) const;
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