#pragma once

#include "Graphics.h"
#include "Sound.h"
#include "PixelFont.h"

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
			Number
		};
	public:
		void SpawnChili();
		bool HasChili() const;
		void SetCellState(State in_state);
		void SetCellIndex(int ind);
		int GetCellIndex() const;
		void DrawCell( const Vei2& screenPos,Field::Mode fieldmode,Graphics& gfx, const PixelFont& font) const;
	private:
		int cellindex;
		int cellwidth=50;
		State state = State::Empty;
	};
public:
	Field( Vei2& center,int in_width,int in_height, int cell_w, Mode mode_in,const PixelFont& in_font );
	~Field();
	void Draw( Graphics& gfx ) const;
private:
	Field::Cell & CellAt(const int gridPos);
	const Cell& CellAt( int gridPos ) const;
private:
	int width;
	int height;
	int cellwidth;
	Vei2 pos;
	Mode mode = Mode::Classic;
	const PixelFont& font;
	Cell* field = nullptr;
};