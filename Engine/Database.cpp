#include "Database.h"

Database::Entry::Entry(const char * entry, int val, Field::Mode in_mode)
	:
	value(val),
	mode(in_mode)
{
	stringcopy(entry,this->name,sizeof(this->name));
}


void Database::Entry::Print(Graphics& gfx,const PixelFont& font,Vei2& pos) const
{ 
	std::string nameandvalue = name + std::string("  ") + std::to_string(value);
	font.DrawString(pos, nameandvalue,gfx,2,Colors::Green);
}

void Database::Entry::Serialize(std::ofstream & out) const
{
	out.write(name, sizeof(name));
	out.write(reinterpret_cast<const char*> (&value), sizeof(value));
	out.write(reinterpret_cast<const char*> (&mode), sizeof(mode));
}

void Database::Entry::Deserialize(std::ifstream & in)
{
	in.read(name, sizeof(name));
	in.read(reinterpret_cast<char*> (&value), sizeof(value));
	in.read(reinterpret_cast<char*> (&mode), sizeof(mode));
}

Field::Mode Database::Entry::GetDatabaseMode() const
{
	return mode;
}

void Database::Entry::stringcopy(const char * pSrc, char * pDst, int maxsize)
{
	int n = 0;
	for (; *pSrc!= 0&&(n+1<maxsize); pSrc++, pDst++) {
		*pDst = *pSrc;
		n++;
	}
	*pDst = 0;
}


void Database::Load(const char * filename)
{
	std::ifstream in(filename, std::ios::binary);
	int nEntries;
	in.read(reinterpret_cast<char*>(&nEntries), sizeof(nEntries));
	entries.resize(nEntries);
	for (auto& e : entries) {
		e.Deserialize(in);
	}
}

void Database::Save(const char * filename)
{
	std::ofstream out(filename, std::ios::binary);
	const int size = int(entries.size());
	out.write(reinterpret_cast<const char*>(&size), sizeof(size));
	std::stable_sort(entries.begin(), entries.end());
	for (const Entry& e : entries) {
		e.Serialize(out);
	}
}

void Database::Print(Graphics& gfx, const Vei2& pos, const PixelFont& font, Field::Mode mode) const
{
	Vei2 update_pos = pos;
	
	font.DrawString(update_pos, "highscores", gfx, 3, Colors::Green);
	update_pos.y += 36;
	switch (mode) {
	case Field::Mode::Classic:
		font.DrawString(update_pos, "classic", gfx, 3, Colors::Green);
		break;
	case Field::Mode::Mouse:
		font.DrawString(update_pos, "mouse", gfx, 3, Colors::Green);
		break;
	case Field::Mode::NumPad:
		font.DrawString(update_pos, "numpad", gfx, 3, Colors::Green);
		break;
	}
	update_pos.y += 36;
	for (const Entry&e : entries) {
		if (e.GetDatabaseMode() == mode) {
			e.Print(gfx, font, update_pos);
			update_pos.y += 24;
		}
	}
}

void Database::Add(const char* name, int value,Field::Mode in_mode)
{
	entries.emplace_back(name, value,in_mode);
}
