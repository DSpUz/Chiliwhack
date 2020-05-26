#pragma once
#include <vector>
#include <fstream>
#include "Vei2.h"
#include "PixelFont.h"
class Database {
private:
	class Entry {
	public:
		Entry() = default;
		Entry(const char* entry, int val);
		void Print(Graphics& gfx,const PixelFont& font,Vei2& pos) const;
		void Serialize(std::ofstream& out) const;
		void Deserialize(std::ifstream& in);
	private:
		void stringcopy(const char* pSrc, char* pDst, int maxsize);
		static constexpr int namebuffersize = 10;
		char name[namebuffersize];
		int value;
	};
public:
	Database() = default;
	void Load(const char* filename);
	void Save(const char* filename) const;
	void Print(Graphics& gfx,const Vei2& pos, const PixelFont& font) const;
	void Add(const char* name, int value);
private:
	std::vector<Entry> entries;
};
