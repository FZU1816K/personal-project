#include<fstream>  //ifstream
#include<iostream>
#include<string>     //包含getline()
#include<algorithm>
#include <vector>
#include<map>
#include<cmath>
#include<stdio.h>
#include<stdio.h>
#include"frequency.h"

using namespace std;

void Frequency::get_filename(string s)
{
	this->Filename = s;
}
void Frequency::word_map()
{
	int a = 0;
	int b = 0;
	w_count = 0;
	c_count = 0;
	lines = 0;
	string word = "";
	int ch_count = 0;//单词长度
	ifstream infile;
	char c;
	infile.open(Filename);

	while (infile.get(c))//输入
	{
		if (c != ' '&&c != '\t'&&c != '\n')
		{
			a = 1;
		}
		else if (c == '\n'&&a == 1)
		{
			lines++;
			a = 0;
		}
		c_count++;
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
				while (infile.eof()) {

					w_count++;
				}
				continue;
			}
			else
			{
				w_count++;
				if (word.size() >= 4)
				{
					//cout << word << endl;
					all_words[word]++;
					ch_count = 0;
					word = "";
				}

			}
		}
	}
	if (a == 1)lines++;
	if (infile.eof())
	{
		if (ch_count >= 4)
			w_count++;
			all_words[word]++;
			//cout << word << endl;
	}
	infile.close();
}
void Frequency::put_map()
{
	ofstream outfile;
	outfile.open(" result.txt");
	//int a[10] = {0,0,0,0,0,0,0,0,0,0};
	int a[10];
	string b[10];
	int num = 0;
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
				num++;
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
		if (a[i] == 0)break;
		if (b[i].size() == 0)
		{
			break;
		}
		outfile << '<' << b[i].c_str() << '>: ' << a[i] << endl;
		printf("<%s>: %d\n", b[i].c_str(), a[i]);
		outfile.close();
	}
}
void Frequency::put_c()
{
	ofstream outfile;
	outfile.open(" result.txt");
	int i;
	i = c_count;
	outfile << "characters: " << i << endl;
	printf("characters: %d\n", i);
	i = w_count;
	outfile << "word: " << i << endl;
	outfile << "lines: " << lines << endl;
	printf("word: %d\n", i);
	printf("lines: %d\n", lines);
	int a[10];
	string b[10];
	int num = 0;
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
				num++;
				flag = it->second;
				a[i] = flag;
				b[i] = it->first;
			}
			k++;
		}
	}
	int k = 0;
	for (k = 0; k < 10; k++)
	{
		if (a[k] == 0)break;
		if (b[k].size() == 0)
		{
			break;
		}
		outfile << '<' << b[k].c_str() << '>: ' << a[k] << endl;
		printf("<%s>: %d\n", b[k].c_str(), a[k]);
	}
	outfile.close();
}
void Frequency::put_words()
{
	ofstream outfile;
	outfile.open(" result.txt");
	int i;
	i = w_count;
	outfile << "word: " << i << endl;
	outfile << "lines: " << lines << endl;
	printf("word: %d\n", i);
	printf("lines: %d\n", lines);
	//outfile.close();
}
