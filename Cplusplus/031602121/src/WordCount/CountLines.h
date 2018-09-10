#pragma once
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
int  CountLines(char *filename)
{
	int num = 0;
	ifstream in(filename);
	char word[1000];
	while (in.getline(word, 1000))
		num++;
	return num;
}