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

map<string, int>  Countwords()
{
	ifstream infile;
	infile.open("input.txt");
	int count = 0, row_count = 1;
	char c;

	infile >> noskipws;

	map<string, int> strMap;
	while (!infile.eof())
	{
		
		infile >> c;  //按照字符输出
		//cout << c << endl;
		//cout << i++ << endl;
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		{
			c = lower(c);
			char word[20] = {};
			int k = 0, c_count = 0;
			int num = 0;
			int flag = 0;
			while ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))  //前四个是否为字母
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
			int i = 0;
			while (c != 32 && c != 10 && c !=03&&!infile.eof()) 
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