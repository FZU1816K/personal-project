#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int CountChar()
{	//char *filename
	ifstream infile;
	infile.open("input.txt");
	char c;
	int count = 0;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;  //°´ÕÕ×Ö·ûÊä³ö
		//cout << c << endl;
		count++;
	}
	infile.close();
	return count-1;
}