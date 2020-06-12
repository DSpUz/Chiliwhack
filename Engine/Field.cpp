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

Field::Cell::State Field::Cell::GetCellState()
{
	return state;
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
			font.DrawCharacter(screenPos.x - fontsize * 4, screenPos.y - fontsize * 4, gfx, 49 + fieldwidth * GridIndex.y + GridIndex.x, fontsize, { 0,128,0 });
			break;
		case State::Chili:
			SpriteCodex::DrawCell(screenPos, cellwidth, cellwidth / 20, 0, 255, 0, gfx);
			SpriteCodex::DrawChili(screenPos, cellwidth*3/4, gfx);
			break;
		case State::NumberPressed:
			SpriteCodex::DrawCell(screenPos, cellwidth, cellwidth / 20, 0, 255, 0, gfx);
			font.DrawCharacter(screenPos.x - fontsize * 4, screenPos.y - fontsize * 4, gfx, 49 + fieldwidth * GridIndex.y + GridIndex.x, fontsize, { 0,255,0 });
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

Field::Field(const Field & source):
	width(source.width),
	height(source.height),
	cellwidth(source.cellwidth),
	pos(source.pos),
	mode(source.mode),
	font(source.font),

	field(new Cell[source.width * source.height])
{
	for (int i = 0; i < source.width * source.height; i++) {
		field[i] = source[i];
	}
}

Field & Field::operator=(const Field & source)
{
	delete[] field;
	field = nullptr;
	field = new Cell[source.width * source.height];
	for (int i = 0; i < source.width * source.height; i++) {
		field[i] = source[i];
	}
	return *this;
}


Field::~Field()
{
	delete [] field;
	field = nullptr;
}

Field::Cell & Field::operator[](int index)
{
	return field[index];
}

const Field::Cell & Field::operator[](int index) const
{
	return field[index];
}

void Field::KeyboardInput(const Keyboard::Event & e)
{
	if (e.IsPress()) {
		const int number = int(e.GetCode());
		switch (number)
		{
		case 97: //Numpad 1	
			field[6].SetCellState(Cell::State::NumberPressed);
			break;
		case 98://Numpad2
			field[7].SetCellState(Cell::State::NumberPressed);
			break;
		case 99: //Numpad3	
			field[8].SetCellState(Cell::State::NumberPressed);
			break;
		case 100://Numpad4
			field[3].SetCellState(Cell::State::NumberPressed);
			break;
		case 101: //Numpad5	
			field[4].SetCellState(Cell::State::NumberPressed);
			break;
		case 102://Numpad6
			field[5].SetCellState(Cell::State::NumberPressed);
			break;
		case 103: //Numpad7	
			field[0].SetCellState(Cell::State::NumberPressed);
			break;
		case 104://Numpad8
			field[1].SetCellState(Cell::State::NumberPressed);
			break;
		case 105://Numpad9
			field[2].SetCellState(Cell::State::NumberPressed);
			break;
		}
	}
	else {
		for (int i = 0; i<this->width*this->height;i++) {
			if (field[i].GetCellState() == Cell::State::NumberPressed) {
				field[i].SetCellState(Cell::State::Number);
			}
		}
	}
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