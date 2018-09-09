#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int Countlines(char *filename)
{	//
	ifstream infile;
	if (filename == nullptr)  //为了vs调试方便
	{
		infile.open("input.txt");
	}
	else infile.open(filename);
	char c;
	int row_count = 0,flag1=0,flag2=0;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;  //按照字符输出
		if (c != 10 && c!=' ')
		{
			flag1 = 1;
			cout << int(c+1)<< endl;
		}
		if (c == 10)
		{
			cout << "1" << endl;
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