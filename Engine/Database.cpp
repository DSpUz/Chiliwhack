#include "Database.h"

Database::Entry::Entry(const char * entry, int val)
	:
	value(val)
{
	std::strcpy(this->name,entry);
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
}

void Database::Entry::Deserialize(std::ifstream & in)
{
	in.read(name, sizeof(name));
	in.read(reinterpret_cast<char*> (&value), sizeof(value));
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

void Database::Save(const char * filename) const
{
	std::ofstream out(filename, std::ios::binary);
	const int size = entries.size();
	out.write(reinterpret_cast<const char*>(&size), sizeof(size));
	for (const Entry& e : entries) {
		e.Serialize(out);
	}
}

void Database::Print(Graphics& gfx, const Vei2& pos, const PixelFont& font) const
{
	Vei2 update_pos = pos;
	for (const Entry&e : entries) {
		e.Print(gfx,font,update_pos);
		update_pos.y += 18;
	}
}

void Database::Add(const char* name, int value)
{
	entries.emplace_back(name, value);
}
