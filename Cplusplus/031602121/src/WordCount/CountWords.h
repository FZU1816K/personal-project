#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cassert>
#include <algorithm>
using namespace std;
int CountWords(char *filename)
{
	ifstream in(filename);          //  打开文件
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
	char word[10000];
	string ss;
	int WordNum=0;
	while (in.getline(word, 10000))         //   istream &in 遇到空白字符（空格符、制表符和换行符）即停止读入。
	{
		ss = word;
		for (int i = 0; i < ss.length(); i++)//对每行的操作
		{
			int count = 0;
			for (int k = i;; k++)//判断是否符合需求中单词的样子
			{

				if (ss[k] >= 'a'&&ss[k] <= 'z')
					count++;
				else if (ss[k] >= 'A'&&ss[k] <= 'Z')
				{
					count++;

				}
				else if (ss[k] >= '0'&&ss[k] <= '9'&&count >= 4)
					count++;
				else break;
			}
			if (count >= 4) //若符合要求，则记录
			{
				char words[100] = { '\0' };
				for (int k = i; k < i + count; k++)
				{
					words[k - i] = ss[k];
				}
			
				WordNum++;//统计总单词数
				i += count - 1;
			}
			else if (count>0 && count<4)i += count - 1;
			else continue;
		}

	}
	return WordNum;
}