#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int Countlines(char *filename)
{
	ifstream infile;
	if (filename == nullptr)  //Easy to debug
	{
		infile.open("input.txt");
	}
	else infile.open(filename);

	if (!infile) exit(1);
	char c;
	int row_count = 0, flag1 = 0;
	infile >> noskipws;

	// if (!infile.eof()) return 0;

	while (infile >> c)
	{
		if (infile.eof()) break;
		if (c != 10 && c != ' '&&c != '\t') //Filter spaces, carriage returns, horizontal tabs
		{
			flag1 = 1;
		}
		if (c == 10)
		{
			//cout << "1" << endl;
			if (flag1 == 1)
			{
				flag1 = 0;
				row_count++;
			}
		}
	}
	if (flag1 == 1) row_count++;
	infile.close();
	return row_count;
}