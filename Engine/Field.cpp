#include "Field.h"
#include <assert.h>
#include <random>
#include "Vei2.h"
#include "SpriteCodex.h"
#include <algorithm>

void Field::Cell::SpawnChili()
{
	assert(state != State::Chili);
	state = State::Chili;
}

bool Field::Cell::HasChili() const
{
	return state == State::Chili;
}

void Field::Cell::SetCellState(State in_state)
{
	state = in_state;
}

void Field::Cell::SetCellIndex(int ind)
{
	cellindex = ind;
}

int Field::Cell::GetCellIndex() const
{
	return cellindex;
}

void Field::Cell::SetCellWidth(int w)
{
	cellwidth = w;
}

void Field::Cell::DrawCell( const Vei2& screenPos,Field::Mode fieldmode,Graphics& gfx,const PixelFont& font) const
{
	if( fieldmode == Field::Mode::Classic )
	{
		switch( state )
		{
		case State::Empty:
			SpriteCodex::DrawCell( screenPos,cellwidth,cellwidth/20,0,255,0,gfx );
			break;
		case State::Chili:
			SpriteCodex::DrawCell(screenPos, cellwidth, cellwidth / 20, 0, 255, 0, gfx);
			SpriteCodex::DrawChili( screenPos, cellwidth/2,gfx);
			break;
		default:
			break;
		}
	}
	else // NumPad
	{
		switch( state )
		{
		case State::Number:
			SpriteCodex::DrawCell(screenPos, cellwidth, cellwidth / 20, 0, 255, 0, gfx);
			font.DrawCharacter(screenPos.x, screenPos.y, gfx, 49 + cellindex, 4, Colors::Green);
			break;
		case State::Chili:
			SpriteCodex::DrawCell(screenPos, cellwidth, cellwidth / 20, 0, 255, 0, gfx);
			SpriteCodex::DrawChili(screenPos, cellwidth / 2, gfx);
			break;
		default:
			break;
		}
	}
}



Field::Field( Vei2& center,int in_width,int in_height,int cell_w, Mode mode_in,const PixelFont& in_font)
	:
	width( in_width ),
	height( in_height ),
	cellwidth(cell_w),
	pos(center),
	font(in_font),
	mode(mode_in),
	
	field( new Cell[in_width * in_height] )
{
	if (mode==Mode::NumPad) {
		for (int i = 0; i < in_width * in_height; i++) {
			CellAt(i).SetCellState(Cell::State::Number);
			CellAt(i).SetCellIndex(i);
			CellAt(i).SetCellWidth(cellwidth);
		}
	}
	else {
		for (int i = 0; i < in_width * in_height; i++) {
			CellAt(i).SetCellIndex(i);
			CellAt(i).SetCellWidth(cellwidth);
		}
	}
	std::random_device rd;
	std::mt19937 rng( rd() );
	std::uniform_int_distribution<int> Dist( 0,width*height - 1 );
	int spawnPos=Dist(rng);
	CellAt(spawnPos).SpawnChili();
}


Field::~Field()
{
	delete[] field;
	field = nullptr;
}

void Field::Draw( Graphics& gfx ) const
{
	
	
	const Vei2 topLeft = { pos.x - cellwidth*(1-width)/ 2, pos.y - cellwidth * (1 - height) / 2 }; //upper left corner coordinates 
	for( int y=0; y < height; y++ )//rows
	{
		for(int x = 0; x < width; x++ )//column index
		{
			CellAt(x*y + x).DrawCell({topLeft.x+2*cellwidth*x,topLeft.y+2*cellwidth*y},mode,gfx,font);
		}
	}
}








Field::Cell& Field::CellAt( const int gridPos )
{
	return field[gridPos];
}

const Field::Cell& Field::CellAt( const int gridPos ) const
{
	return field[gridPos];
}
