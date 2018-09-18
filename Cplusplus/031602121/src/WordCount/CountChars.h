#pragma once
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
int CountChars(char *filename)
{
	char word[10000];
	size_t num=0;
	string a;
	ifstream in(filename);
	while (in.getline(word, 10000))
	{
		a = word;
		num +=( a.length()+1);
	}
	return num;
}