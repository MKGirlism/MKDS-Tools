#ifndef TLDR_H_
#define TLDR_H_
#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <cerrno>
#include <iostream>

using namespace std;

class Couting {
public:
	void CourseList();
};

class FileIO {
public:
	string GetFileContents(const char *filename);
};

#endif
