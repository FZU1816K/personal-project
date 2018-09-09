#include<iostream>
#include<fstream>
#include<string>
#include "Clines.h"
using namespace std;

Line::Line(string file)
{
	finname = file;
	number = 0;
	foutname = "result.txt";
}

void Line::count()
{
	ifstream fin;
	fin.open(finname);
	if (!fin.is_open())
	{
		cerr << "Could not open" << finname << endl;
		fin.clear();
	}
	char buffer[1000];
	while (fin.good())
	{
		fin.getline(buffer, 1000, '\n');
		if (buffer[0] != '\n')
			number++;
	}
	if (fin.eof())
		;
	if (fin.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	fin.close();
}

void Line::show()
{
	cout << "lines:" << number << endl;
}

void Line::fwrite()
{
	ofstream fout;
	fout.open(foutname, ios::out | ios::app); //×·¼Ó
	if (!fout.is_open())
	{
		cerr << "Cant't open" << foutname << endl;
		exit(EXIT_FAILURE);
	}
	fout << "lines:" << number << endl;
	fout.close();
}