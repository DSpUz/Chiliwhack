#pragma once

#include "Graphics.h"
#include "Sound.h"
#include "PixelFont.h"
#include "Keyboard.h"

class Field
{
public:
	enum class Mode
	{
		Classic,
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
	void KeyboardInput(const Keyboard::Event& e);
	void Draw( Graphics& gfx ) const;
	int GetWidth() const;
	int GetHeight() const;
private:
	int width;
	int height;
	int cellwidth;
	Vei2 pos;
	Mode mode;
	const PixelFont& font;
	Cell* field = nullptr;
};