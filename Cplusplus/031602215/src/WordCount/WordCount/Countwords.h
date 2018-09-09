#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>

using namespace std;


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
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		{
			char word[20] = {};
			int k = 0, c_count = 0;
			int num = 0;
			int flag = 0;
			while ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))  //前四个是否为字母
			{
				word[k++] = c;
				infile >> c;
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
			while (c != 32 && c != 10) //结尾会出现bug
			{
				//cout << c << endl;
				if (flag == 1)
				{
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