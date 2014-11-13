#include "tldr.h"

void Couting::CourseList() {
	cout << "1: GCN Yoshi Circuit\n"
		"2-8 Unused Slots\n"
		"9: GCN Baby Park\n"
		"10: SNES Mario Circuit 1\n"
		"11: N64 Moo Moo Farm\n"
		"12: GBA Bowser Castle\n"
		"13: GBA Peach Circuit\n"
		"14: GCN Luigi Circuit\n"
		"15: SNES Koopa Beach 2\n"
		"16: N64 Frappe Snowland\n"
		"17: Tick-Tock Clock\n"
		"18: Luigi's Mansion\n"
		"19: Airship Fortress\n"
		"20: Figure-8 Circuit\n"
		"21: Unused slot\n"
		"22: Yoshi Falls\n"
		"23: N64 Banshee Boardwalk\n"
		"24: Shoom Ridge\n"
		"25: Mario Circuit\n"
		"26: Peach Gardens\n"
		"27: Desert Hills\n"
		"28: Delfino Square\n"
		"29: Rainbow Road\n"
		"30: DK Pass\n"
		"31: Cheep Cheep Beach\n"
		"32: Bowser Castle\n"
		"33: Waluigi Pinball\n"
		"34: Wario Stadium\n"
		"35: SNES Donut Plains\n"
		"36: N64 Choco Mountain\n"
		"37: GBA Luigi Circuit\n"
		"38: GCN Mushroom Bridge\n"
		"39: SNES Choco Island\n"
		"40: GBA Sky Garden\n"  << endl;
}

string FileIO::GetFileContents(string filename) {
		ifstream myfile (filename);
		if (myfile.is_open())
  			{
    			ostringstream contents;
    			contents << myfile.rdbuf();
			myfile.close();
    			return (contents.str());
  			}  else {
				cout << "There isn't a valid file called " + filename + " in your directory.\nCheck if it really is there.\n";
				exit(1);
			}
}
