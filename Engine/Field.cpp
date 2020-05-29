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

void Field::Cell::SetCellIndex(int x, int y)
{
	GridIndex.x = x;
	GridIndex.y = y;
}


 Vei2 Field::Cell::GetCellIndex() const
{
	return GridIndex;
}

void Field::Cell::SetCellWidth(int w)
{
	cellwidth = w;
}

void Field::Cell::DrawCell(const Vei2& screenPos,int fieldwidth ,Field::Mode fieldmode,Graphics& gfx,const PixelFont& font) const
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
			SpriteCodex::DrawChili( screenPos, cellwidth*3/4,gfx);
			break;
		default:
			break;
		}
	}
	else // NumPad
	{
		int fontsize = 3;
		switch( state )
		{
		case State::Number:
			SpriteCodex::DrawCell(screenPos, cellwidth, cellwidth / 20, 0, 255, 0, gfx);
			font.DrawCharacter(screenPos.x-fontsize*4, screenPos.y-fontsize*4, gfx, 49 + fieldwidth*GridIndex.y+GridIndex.x, fontsize, Colors::Green);
			break;
		case State::Chili:
			SpriteCodex::DrawCell(screenPos, cellwidth, cellwidth / 20, 0, 255, 0, gfx);
			SpriteCodex::DrawChili(screenPos, cellwidth*3/4, gfx);
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
		for (int y = 0; y <height; y++) {
			for (int x = 0; x < width; x++) {
				field[width*y+x].SetCellState(Cell::State::Number);
				field[width*y+x].SetCellIndex(x,y);
				field[width*y+x].SetCellWidth(cellwidth);
			}
		}
	}
	else {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				field[width*y + x].SetCellIndex(x, y);
				field[width*y + x].SetCellWidth(cellwidth);
			}
		}
	}
	std::random_device rd;
	std::mt19937 rng( rd() );
	std::uniform_int_distribution<int> Dist( 0,width*height - 1 );
	int spawnPos=Dist(rng);
	field[spawnPos].SpawnChili();
}


Field::~Field()
{
	delete[] field;
	field = nullptr;
}

void Field::Draw( Graphics& gfx ) const
{
	
	
	const Vei2 topLeft = { pos.x + cellwidth*(1-width), pos.y + cellwidth * (1 - height) }; //upper left corner coordinates 
	for( int y=0; y < height; y++ )//rows
	{
		for(int x = 0; x < width; x++ )//column index
		{
			field[width*y + x].DrawCell({topLeft.x+2*cellwidth*x,topLeft.y+2*cellwidth*y},width,mode,gfx,font);
		}
	}
}

int Field::GetWidth() const
{
	return width;
}

int Field::GetHeight() const
{
	return height;
}








Field::Cell& Field::CellAt( const int gridPos )
{
	return field[gridPos];
}

const Field::Cell& Field::CellAt( const int gridPos ) const
{
	return field[gridPos];
}
