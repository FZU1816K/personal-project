#include<iostream>
#include<fstream>
#include<string>
#include "Ccharacter.h"
using namespace std;

Character::Character(string file)
{
	finname = file;
	number = 0;
	foutname = "result.txt";
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
	///////////////////////////////
//	ofstream fout;
//	fout.open(foutname, ios::out);
	///////////////////////////////
	while (!fin.eof())
	{
		/////////////
//		fout << c<<endl;
		/////////////
		if(c>=0&&c<=127)
			++number;
		fin >> c;
	}
	///////////////
//	fout.close();
	//////////////
	fin.close();
}

void Character::show()
{
	cout << "characters:" << number << endl;
}

void Character::fwrite()
{
	ofstream fout;
	fout.open(foutname, ios::out);
	if (!fout.is_open())
	{
		cerr << "Cant't open" << foutname << endl;
		exit(EXIT_FAILURE);
	}
	fout << "characters:" << number << endl;
	fout.close();
}