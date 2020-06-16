#pragma once

#include "Graphics.h"
#include "Sound.h"
#include "PixelFont.h"
#include "Keyboard.h"
#include "Hammer.h"
#include "randomGenerator.h"

class Field
{
public:
	enum class Mode
	{
		Classic,
		Mouse,
		NumPad
	};
private:
	class Cell
	{
	public:
		enum class State
		{
			Empty,
			Chili,
			Number,
			NumberPressed
		};
	public:
		void SpawnChili();
		bool HasChili() const;
		void SetCellState(State in_state);
		State GetCellState();
		void SetCellIndex(int x,int y);
		Vei2 GetCellIndex() const;
		void SetCellWidth(int w);
		int flipnumpadnumber(int input) const;
		void DrawCell( const Vei2& screenPos, int fieldwidth, Field::Mode fieldmode,Graphics& gfx, const PixelFont& font) const;
	private:
		int cellwidth;
		Vei2 GridIndex;
		State state = State::Empty;
	};
public:
	Field( Vei2& center,int in_width,int in_height, int cell_w, Mode mode_in,const PixelFont& in_font );
	Field(const Field& source);
	Field& operator=(const Field& source);
	~Field();
	Field::Cell& operator[](int index);
	const Field::Cell& operator[](int index) const;
	void MouseInput(const Mouse::Event& e, float dt, bool noinput, int& chilicounter);
	void KeyboardInput(const Keyboard::Event& e, float dt, bool noinput, int& chilicounter);
	void NumPadInput(const Keyboard::Event& e, int& chilicounter);
	int GetCellIndexFromPos(const Vei2& hammerpos) const;
	void Draw( Graphics& gfx ) const;
	int GetWidth() const;
	int GetHeight() const;
private:
	int width;
	int height;
	int cellwidth;
	RandomGenerator<std::mt19937> randChili;
	Sound phone1 = { L"phone1.wav" }, phone2 = { L"phone2.wav" }, phone3 = { L"phone3.wav" }, phone4 = { L"phone4.wav" }, phone5 = { L"phone5.wav" }
	, phone6 = { L"phone6.wav" }, phone7 = { L"phone7.wav" }, phone8 = { L"phone8.wav" }, phone9 = { L"phone9.wav" };
	bool sfxplayedonce=false;
	Vei2 pos;
	const RectI fieldrect = { pos.x - cellwidth * width, pos.x + cellwidth * width, pos.y - cellwidth * height,  pos.y + cellwidth * height };
	Mode mode;
	const PixelFont& font;
	Hammer fieldhammer;
	Cell* field = nullptr;
};