#include<iostream>
#include<fstream>
#include<string>
#include "Cwords.h"
using namespace std;

Word::Word() {}

Word::Word(string file)
{
	finname = file;
	number = 0;
	foutname = "result.txt";
}

int Word::get()
{
	return number;
}

void Word::count()
{
	ifstream fin;
	fin.open(finname);
	if (!fin.is_open())
	{
		cerr << "Could not open " << finname << endl;
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
}

void Word::show()
{
	printf("words:%d\n", number);
}

void Word::fwrite()
{
	ofstream fout;
	fout.open(foutname, ios::out | ios::app); //追加
	if (!fout.is_open())
	{
		cerr << "Cant't open" << foutname << endl;
		exit(EXIT_FAILURE);
	}
	fout << "words:" << number << endl;
	fout.close();
}