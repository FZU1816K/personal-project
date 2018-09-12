#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
using namespace std;
char lower(char c)
{
	if ((c >= 'A'&&c <= 'Z'))
	{
		return c + 32;
	}
	return c;
}
bool whether_char(char c)
{
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9')) return true;
	else return false;
}
map<string, int>  Countwords(char *filename)
{
	ifstream infile;
	if (filename == nullptr)
	{
		infile.open("input.txt");
	}

	else infile.open(filename);
	if (!infile) exit(1);

	int count = 0, row_count = 1;
	char c;

	infile >> noskipws;

	map<string, int> strMap;
	while (!infile.eof())
	{
		
		infile >> c;  //read character

		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		{
			c = lower(c);
			char word[20] = {};
			int k = 0, c_count = 0;
			int num = 0;
			int flag = 0;
			while ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))  //Whether the first four are character
			{
				word[k++] = c;
				infile >> c;
				c = lower(c);
				num++;
				if (num > 3)
				{
					flag = 1;
					num = 0;
					break;
				}
			}
			//cout << c << endl;
			//cout << flag;
			//int i = 0;
			while (whether_char(c)&&!infile.eof()) 
			{
				//cout << i++ << endl;
				if (flag == 1)
				{
					c = lower(c);
					word[k++] = c;
				}
				infile >> c;
			}
			if (flag == 1)
			{
				if (strMap.find(word) != strMap.end())	strMap[word]++;
				else strMap[word] = 1;
			}

		}
	}
	infile.close();
	return  strMap;
}