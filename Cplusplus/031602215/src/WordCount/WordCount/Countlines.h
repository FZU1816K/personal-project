#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int Countlines()
{	//char *filename
	ifstream infile;
	infile.open("input.txt");
	char c;
	int row_count = 0,flag1=0,flag2=0;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;  //°´ÕÕ×Ö·ûÊä³ö
		if (c != 10 && c!=' ' && infile.eof())
		{
			flag1 = 1;
		}
		if (c == 10)
		{
			if (flag1 == 1)
			{
				flag1 = 0;
				row_count++;
			}
		}
	}
	infile.close();
	return row_count + 1;
}