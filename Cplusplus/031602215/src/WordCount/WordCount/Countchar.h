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

	if (!infile) exit(1);

	infile >> noskipws; //To force read in each character, do not filter whitespace, including line breaks
	char c;
	int count = 0;
	while (!infile.eof())
	{
		infile >> c;  //read character
		count++;
	}
	infile.close();
	return count-1;
}