#include <iostream>
#include <fstream>

using namespace std;

// demo of advanced file IO
// read Gaddis Ch. 12 for more info

int main() {
	string line;
	// can use fstream to open a file for both reading and writing
	fstream file;
	
	// open for writing
	file.open("words.txt", ios::out);
	file << "hello" << endl;
	// can query current position of file cursor with tellg() for reading and tellp() for writing
	long position = file.tellg(); // 6 because wrote 6 bytes: h e l l o \n
	cout << "Current position: " << position << endl;
	file.close();
	
	// open for reading and writing
	file.open("words.txt", ios::in | ios::out); // the | is called pipe and combines two flags using binary or
	while (!file.eof()) {
		getline(file, line);
		if (file.good()) {
			cout << "Read: " << line << endl;
		}
	}
	
	// can move file cursor with seekg(offset, from) for reading and seekp(offset, from) for writing
	// move file cursor to beginning of file (0 offset from beginning)
	file.clear(); // clear EOF bit (flag)
	file.seekp(0, ios::beg);
	
	file << "goodbye" << endl; // overwrites hello
	file.close();
	
	// other open flags
	// ios::in reading
	// ios::out writing
	// ios::app appending (writing only to end of file and cannot move cursor)
	// ios::ate at end (writing starts at end of file but can move cursor)
	// ios::binary open file in binar mode
	
	// other seekp() seekg() flags include
	// ios::beg beginning of stream
	// ios::end end of stream
	// ios::cur current position in stream
	

	return 0;
}
