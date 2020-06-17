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

int Field::Cell::flipnumpadnumber(int input) const
{
	switch (input) {
	case 49:
		return 55;
		break;
	case 50:
		return 56;
		break;
	case 51:
		return 57;
		break;
	case 52:
		return 52;
		break;
	case 53:
		return 53;
		break;
	case 54:
		return 54;
		break;
	case 55:
		return 49;
		break;
	case 56:
		return 50;
		break;
	case 57:
		return 51;
		break;
	default: 
		return 0;
		break;
	}
}

void Field::Cell::DrawCell(const Vei2& screenPos,int fieldwidth ,Field::Mode fieldmode,Graphics& gfx,const PixelFont& font) const
{
	if( fieldmode == Field::Mode::Classic )
	{
		switch( state )
		{
		case State::Empty:
			SpriteCodex::DrawCell( screenPos,cellwidth,4,102,178,255,gfx );
			break;
		case State::Chili:
			SpriteCodex::DrawCell(screenPos, cellwidth, 4, 102, 178, 255, gfx);
			SpriteCodex::DrawChili( screenPos, cellwidth*4/3,gfx);
			break;
		default:
			break;
		}
	}
	else // NumPad
	{
		int fontsize = 4;
		switch( state )
		{
		case State::Number:
			SpriteCodex::DrawCell(screenPos, cellwidth, 4, 102, 178, 255, gfx);
			font.DrawCharacter(screenPos.x - fontsize * 4, screenPos.y - fontsize * 4, gfx,flipnumpadnumber( 49 + fieldwidth * GridIndex.y + GridIndex.x), fontsize, { 0,60,0 });
			break;
		case State::Chili:
			SpriteCodex::DrawCell(screenPos, cellwidth,4, 102, 178, 255, gfx);
			SpriteCodex::DrawChili(screenPos, cellwidth*4/3, gfx);
			break;
		case State::NumberPressed:
			SpriteCodex::DrawCell(screenPos, cellwidth, 4, 102, 178, 255, gfx);
			font.DrawCharacter(screenPos.x - fontsize * 4, screenPos.y - fontsize * 4, gfx,flipnumpadnumber( 49 + fieldwidth * GridIndex.y + GridIndex.x), fontsize, { 80,255,0 });
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
	fieldhammer(pos,Hammer::hammerState::StillUp),
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
	fieldhammer(pos,Hammer::hammerState::StillUp),

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

void Field::MouseInput(const Mouse::Event & e, float dt, bool noinput, int& chilicounter)
{
	fieldhammer.MouseUpdate(dt, e, noinput);
	const int cellindex = GetCellIndexFromPos(fieldhammer.GetPos());
	if (cellindex < width*height) {
		if (fieldhammer.IsHammerPressed() && field[cellindex].HasChili()) {
			field[cellindex].SetCellState(Cell::State::Empty);
			chilicounter++;
			int newindex = randChili.Get<int>(0, width*height - 1);
			while (newindex == cellindex) {
				newindex = randChili.Get<int>(0, width*height - 1);
			}
			field[newindex].SpawnChili();
		}
	}
}

void Field::KeyboardInput(const Keyboard::Event & e, float dt, bool noinput,int& chilicounter)
{
	fieldhammer.KeyboardUpdate(dt, e, noinput, cellwidth);
	const int cellindex = GetCellIndexFromPos(fieldhammer.GetPos());
	if (cellindex < width*height) {
		if (fieldhammer.IsHammerPressed() && field[cellindex].HasChili()) {
			field[cellindex].SetCellState(Cell::State::Empty);
			chilicounter++;
			int newindex= randChili.Get<int>(0, width*height - 1);
			while (newindex == cellindex) {
				newindex = randChili.Get<int>(0, width*height - 1);
			}
			field[newindex].SpawnChili();
		}
	}
}

void Field::NumPadInput(const Keyboard::Event & e, int& chilicounter)
{
	if (e.IsPress()) {
		const int number = int(e.GetCode());
		switch (number)
		{
		case 97: //Numpad 1	
			if (field[6].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 6) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[6].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone1.Play();
				sfxplayedonce = true;
			}
			
			break;
		case 98://Numpad2
			if (field[7].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 7) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[7].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone2.Play();
				sfxplayedonce = true;
			}
		
			break;
		case 99: //Numpad3	
			if (field[8].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 8) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[8].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone3.Play();
				sfxplayedonce = true;
			}
		
			break;
		case 100://Numpad4
			if (field[3].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 3) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[3].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone4.Play();
				sfxplayedonce = true;
			}
		
			break;
		case 101: //Numpad5	
			if (field[4].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 4) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[4].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone5.Play();
				sfxplayedonce = true;
			}
		
			break;
		case 102://Numpad6
			if (field[5].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 5) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[5].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone6.Play();
				sfxplayedonce = true;
			}
		
			break;
		case 103: //Numpad7	
			if (field[0].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 0) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[0].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone7.Play();
				sfxplayedonce = true;
			}
			break;
		case 104://Numpad8
			if (field[1].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 1) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[1].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone8.Play();
				sfxplayedonce = true;
			}
		
			break;
		case 105://Numpad9
			if (field[2].HasChili()) {
				chilicounter++;
				int newindex = randChili.Get<int>(0, width*height - 1);
				while (newindex == 2) {
					newindex = randChili.Get<int>(0, width*height - 1);
				}
				field[newindex].SpawnChili();
			}
			field[2].SetCellState(Cell::State::NumberPressed);
			if (!sfxplayedonce) {
				phone1.StopAll(); phone2.StopAll(); phone3.StopAll(); phone4.StopAll(); phone5.StopAll(); phone6.StopAll(); phone7.StopAll(); phone8.StopAll(); phone9.StopAll();
				phone9.Play();
				sfxplayedonce = true;
			}
			break;
		}
	}
	else if(e.IsRelease()){
		for (int i = 0; i<this->width*this->height;i++) {
			Cell::State cellstate = field[i].GetCellState();
			if (cellstate == Cell::State::NumberPressed) {
				field[i].SetCellState(Cell::State::Number);
			}
		}
		sfxplayedonce = false;
	}
}

Field::Mode Field::GetMode() const
{
	return mode;
}

int Field::GetCellIndexFromPos(const Vei2 & hammerpos) const
{
	int cellindex = 0;
	if (fieldrect.Contains(hammerpos)) {
		for (int top = fieldrect.top; top < fieldrect.bottom; top += 2 * cellwidth) {
			for (int left = fieldrect.left; left < fieldrect.right; left += 2 * cellwidth) {
				if(hammerpos.x >= left && hammerpos.x < left+2*cellwidth && hammerpos.y >= top && hammerpos.y < top+2*cellwidth){
					return cellindex;
				}
				cellindex++;
			}
		}
	}
	else { return width * height; }
	return width * height;
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
	if (mode == Mode::Classic||mode==Mode::Mouse) {
		fieldhammer.DrawHammer(gfx);
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