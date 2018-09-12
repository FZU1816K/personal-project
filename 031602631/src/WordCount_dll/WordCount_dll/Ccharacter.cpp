#include<iostream>
#include<fstream>
#include<string>
#include "Ccharacter.h"
using namespace std;

int c_character(std::string &finname)
{
	int number = 0;
	ifstream fin;
	fin.open(finname);
	if (!fin.is_open())
	{
		cerr << "Could not open" << finname << endl;
		fin.clear();
	}
	fin >> noskipws;
	char c;
	fin >> c;
	while (fin.good())
	{
		if (c >= 0 && c <= 127)
			++number;
		fin >> c;
	}
	if (fin.eof()) {}
	else if (fin.fail())
		printf( "Input terminated by data mismatch.\n");
	else
		printf( "Input terminated for unknown reason.\n");
	fin.close();

	return number;
}