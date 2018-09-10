#pragma once
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
int CountChars(char *filename)
{
	char word[1000];
	int num=0;
	string a;
	ifstream in(filename);
	while (in.getline(word, 1000))
	{
		a = word;
		num += a.length();
	}
	return num;
}