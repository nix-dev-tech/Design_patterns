#include<iostream>
#include<vector>
#include<boost/lexical_cast.hpp>
#include<fstream>

using namespace std;
using namespace boost;

struct Journal {
	string title;
	vector<string> entries;
	Journal(const string& title) : title(title) {};
	void addEntry(const string& entry) {
		static int count = 1;
		entries.push_back(lexical_cast<string>(count++) + ": " + entry);
	}

	void printEntry() {
		for (auto entry : entries) {
			cout << entry << endl;
		}
	}
	/*
	Breaks the single responsibility design principle of SOLID design principle.
	Journal class should not have save functionality as it is not responsibility of Journal class.
	We should have seperate persistance manager for save functionality here

	void save(const string& filename) {
		ofstream ofs(filename);
		for (auto& e : entries) {
			ofs << e << endl;
		}
	}*/
};

struct PersistanceManager {
	static void save(const Journal& j, const string& filename) {
		ofstream ofs(filename);
		for (auto& e : j.entries) {
			ofs << e << endl;
		}
	}
};

int main() {
	Journal journal{ "Diary" };
	journal.addEntry("I created design patterns repository on Github today");
	journal.addEntry("I added Single Responsibility design principle today");
	journal.printEntry();

	//journal.save("diary.txt");

	PersistanceManager pm;
	pm.save(journal, "diary.txt");

	return 0;
}
