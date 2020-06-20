#pragma once
#include <vector>
#include <fstream>
#include <algorithm>  
#include "Vei2.h"
#include "PixelFont.h"
#include "Field.h"
class Database {
private:
	class Entry {
	public:
		Entry() = default;
		Entry(const char* entry, int val,Field::Mode mode);
		bool operator<(const Entry& rhs) const {
			return value  > rhs.value;
		}
		void Print(Graphics& gfx,const PixelFont& font,Vei2& pos) const;
		void Serialize(std::ofstream& out) const;
		void Deserialize(std::ifstream& in);

		Field::Mode GetDatabaseMode() const;
	private:
		void stringcopy(const char* pSrc, char* pDst, int maxsize);
		static constexpr int namebuffersize = 10;
		char name[namebuffersize];
		int value;
		Field::Mode mode;
	};
public:
	Database() = default;
	void Load(const char* filename);
	void Save(const char* filename);
	void Print(Graphics& gfx,const Vei2& pos, const PixelFont& font, Field::Mode mode) const;
	void Add(const char* name, int value,Field::Mode in_mode);
private:
	std::vector<Entry> entries;
};
