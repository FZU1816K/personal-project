#include<fstream>  //ifstream
#include<iostream>
#include<string>     //包含getline()
#include<algorithm>
#include <vector>
#include<map>
#include<cmath>
#include<stdio.h>
#include"frequency.h"

using namespace std;

void Frequency::get_filename(string s)
{
	this->Filename = s;
}
void Frequency::word_map()
{
	string word = "";
	int ch_count = 0;//单词长度
	int i = 0;//单词数目
	ifstream infile;
	char c;
	infile.open(Filename);

	while (infile.get(c))//输入
	{
		if ('A' <= c && c <= 'Z')//把大写换成小写
		{
			c = c + 32;
		}
		if (ch_count < 4)//判断单词长度是否大于4
		{
			if (c >= 'a'&&c <= 'z')
			{
				word = word + c;
				ch_count++;
			}
			else
			{
				ch_count = 0;//单词长度初始化
				word = "";//单词初始化
				continue;
			}
		}
		else
		{
			if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9'))
			{
				word = word + c;
				continue;
			}
			else
			{
				all_words[word]++;
				ch_count = 0;
				word = "";

			}
		}
	}
	if (infile.eof())
	{
		if (ch_count >= 4)
			all_words[word]++;
	}
	infile.close();
}
void Frequency::put_map()
{
	int a[10];
	string b[10];
	map<string, int>::iterator it;
	for (int i = 0; i < 10; i++)
	{
		int flag = 0;
		int k = 0;
		int p;
		for (it = all_words.begin(); it != all_words.end(); it++)
		{
			p = 0;
			for (int m = 0; m < i; m++)
			{
				if (b[m] == it->first)
				{
					p = 1;
					break;
				}
			}
			if (p == 1) continue;
			if (it->second > flag)
			{
				flag = it->second;
				a[i] = flag;
				b[i] = it->first;
			}
			k++;
		}
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		cout << b[i] << " : " << a[i] << endl;
	}
}
