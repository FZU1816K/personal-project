#include<iostream>
#include<fstream>
#include<string>
#include "Cwords.h"
using namespace std;

int c_word(std::string &finname)
{
	int number = 0;
	ifstream fin;
	fin.open(finname);
	if (!fin.is_open())
	{
		cerr << "Could not open" << finname << endl;
		fin.clear();
	}
	string word;
	char c;
	fin >> noskipws; //不放过一个字符
	while (fin.good())
	{
		fin >> c;
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) //是字母数字
		{
			if (c >= 65 && c <= 90)
				c += 32;
			word.push_back(c);
		}
		else //判断能否组成单词
		{
			if (word.length() >= 4)
			{
				if ((word[0] >= 97 && word[0] <= 122) && (word[1] >= 97 && word[1] <= 122) && (word[2] >= 97 && word[2] <= 122) && (word[3] >= 97 && word[3] <= 122))
				{
					number++;
				}
			}
			word = "";
		}
	}
	if (fin.eof()) {}
	else if (fin.fail())
		printf("Input terminated by data mismatch.\n");
	else
		printf("Input terminated for unknown reason.\n");
	fin.close();

	return number;
}