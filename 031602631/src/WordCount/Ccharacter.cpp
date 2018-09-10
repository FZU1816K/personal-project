#include<iostream>
#include<fstream>
#include<string>
#include "Ccharacter.h"
using namespace std;

Character::Character() {}

Character::Character(string file)
{
	finname = file;
	number = 0;
	foutname = "result.txt";
}

int Character::get()
{
	return  number;
}
void Character::count()
{
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
	if (fin.eof())
		;
	if (fin.fail())
		printf("Input terminated by data mismatch.\n");
	else
		printf("Input terminated for unknown reason.\n");
	fin.close();
}

void Character::show()
{
	printf("characters:%d\n", number);
}

void Character::fwrite()
{
	ofstream fout;
	fout.open(foutname, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Cant't open" << foutname << endl;
		exit(EXIT_FAILURE);
	}
	fout << "characters:" << number << endl;
	fout.close();
}