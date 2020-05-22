#pragma once
#include <vector>
#include <fstream>
class Database {
private:
	class Entry {
	public:
		Entry() = default;
		Entry(char* entry, int val);
		void Print() const;
		void Serialize(std::ofstream& out) const;
		void Deserialize(std::ifstream& in);
	private:
		static constexpr int namebuffersize = 10;
		char name[namebuffersize];
		int value;
	};
public:
	Database() = default;
	void Load(const char* filename);
	void Save(const char* filename) const;
	void Print() const;
	void Add(const char* name, int value);
private:
	std::vector<Entry> entries;
};
