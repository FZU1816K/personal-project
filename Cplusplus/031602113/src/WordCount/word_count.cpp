#include<fstream>  //ifstream
#include<iostream>
#include<map>
#include<string>     //包含getline()
#include<cmath>
#include"wordcount.h"
using namespace std;

void Wordcount::get_filename(string s)
{
	this->Filename = s;
}
void Wordcount::word_count()
{
	string word = "";
	int ch_count = 0;//单词长度
	int w_count = 0;//单词数目
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
				while (infile.eof()) {

					w_count++;
				}


				continue;
			}
			else {

				w_count++;
				ch_count = 0;
				word = "";

			}
		}
	}
	if (infile.eof())
	{
		if (ch_count >= 4)
			w_count++;
	}
	this->number = w_count;
	infile.close();
}
void Wordcount::put_num()
{

	int i;
	i = this->number;
	cout << "单词数量：" << i << endl;
}