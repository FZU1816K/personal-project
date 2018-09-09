#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int CountChar(char *filename)
{	//char *filename
	ifstream infile;
	if (filename == nullptr)
	{
		infile.open("input.txt");
	}
	else infile.open(filename);
	char c;
	int count = 0;
	while (!infile.eof())
	{
		infile >> c;  //°´ÕÕ×Ö·ûÊä³ö
		//cout << c << endl;
		count++;
	}
	infile.close();
	return count-1;
}