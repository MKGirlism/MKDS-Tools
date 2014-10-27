// Release 1.0. Probably a lot can be optimised, but sigh, it's my first proper tool ever :3
// TYCO - Added courses.txt with and opening it instead of putting it in the code, still doesn't compile but my part should work
// Yami - Removed some unnecessary "STD"'s, as well as made it Compileable on all OS's. Also, I made the Layout more readable. Besides, Tycoonie's TXT File didn't work, so I have separated everything, into a Class.
#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <cerrno>

#include "tldr.h"

using namespace std;

string get_file_contents(const char *filename) {
  	ifstream in(filename, ios::in | ios::binary);
  	if (in){
    		ostringstream contents;
    		contents << in.rdbuf();
    		in.close();
    		
    		return (contents.str());
  	}
  	throw(errno);
}

int main() {
	string text = get_file_contents("staff_ghost_time.bin");

	//Separating string to signs to reverse it
	string array[160];
    	for (int a=0; a<160; a++) {
    		array[a]=text.substr(a, 1);
    	}
    	
    	string convertedarray[40];
    	int array2[40][4];
    	long long finalarray[40];
    	for (int i=0; i<40; i++) {
    		//Reversing value and final string
    		convertedarray[i] = array[i*4+3] + array[i*4+2] + array [i*4+1] + array [i*4];
		for (int f=0; f<4; f++) {
			//String into int
			array2[i][f]=convertedarray[i][f];
			//If string was bigger than 127, give it a value to 255;
			if (array2[i][f]<0) {
				array2[i][f]=array2[i][f]+256;
			}
		}
		//Final time value
		finalarray[i] = array2[i][3]+array2[i][2]*256+array2[i][1]*65536;
    	}
    	
    	cout << "Staff_Ghost_Time.bin editor by Szymbar15, 2014\nCreated for DSHack.org community\nszymbar1513@gmail.com\n*****************\nMake sure you put staff_ghost_time.bin in the same folder as this tool\nDo you want to see some hints on tool usage? \nType \"y\" if you want or anything else if you don\'t: ";
    	char c;
    	cin >> c;
    	if (c == 'y') {
		Couting couting;
    		couting.CourseList();
    	}
    	
    	int y;
	while (y != 41) {
		cout << "\n*****************\nWrite a number from 1 to 40 to load your desired course \nor write 41 to save changes and finish program: ";
		cin >> y;
    		
    		if (y <= 40) {
    			cout << "\nThe current value for this track is: \n"
    				<< finalarray[y-1] << " miliseconds, "
    				<< finalarray[y-1]/1000 <<
    				" seconds.\nWrite new value in miliseconds smaller than 16777216: ";
    			cin >> finalarray[y-1];
    			cout << "\nSuccesfully changed!\nYour new value is: "
    				<< finalarray[y-1] << " miliseconds, " << finalarray[y-1]/1000 << " seconds.\n\n";
    		}
    		
    		else if (y > 41) {
    			cout << "\nWrong number.\n";
    		}
	}
		
	//Hexing file again
	int editedarray[40][4];
	
	//Int to string array
	string stringeditedarray[40][4];
	
	//Final exported string
	string thegloriousfinalone;
	
	if (y == 41) {
		for (int q = 0; q < 40; q++) {
			//Calculating values in hex
			editedarray[q][0] = 0;
			editedarray[q][1] = finalarray[q]/65536;
			editedarray[q][2] = (finalarray[q]%65536)/256;
			editedarray[q][3] = (finalarray[q]%65536)%256;
			for (int j = 0; j < 4; j++) {
				//If value is bigger than 128, make it a minus value
				if (editedarray[q][j] > 127) {
					editedarray[q][j] -= 256;
				}		
			}
			
			//Reversing and creating one sign strings
			stringeditedarray[q][0] = editedarray[q][3];
			stringeditedarray[q][1] = editedarray[q][2];
			stringeditedarray[q][2] = editedarray[q][1];
			stringeditedarray[q][3] = editedarray[q][0];
			
			//And it's done.
			thegloriousfinalone += stringeditedarray[q][0] + stringeditedarray[q][1]
				+ stringeditedarray[q][2] + stringeditedarray[q][3];
		}
		
		//Save as file.
		ofstream out("edited_staff_ghost_time.bin");
    		out << thegloriousfinalone;
    		out.close();
		
		cout << "\nI hope you had fun! :3\nPress any key to quit this tool.\nYou will find the file in your folder called\nedited_staff_ghost_time.bin\n";
	}
	
	cin.get();
	cin.get();
	cout << "" << endl;
	
	// What does this do? It makes it incompileable?
	// The "Main" Function is of type "int", and thus it needs to Return something.
	return 0;
}
