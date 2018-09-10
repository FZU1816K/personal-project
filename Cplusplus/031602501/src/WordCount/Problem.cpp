#include "pch.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include"problem.h"

bool _ischar(char t)										//判断传入的字符是否为数字及字母（是则返回真）
{
	if (t<'0' || (t > '9'&&t < 'a') || t>'z')
		return false;
	else return true;
}
bool _nonumber(char t)										//判断传入的字符是否为字母（是则返回真）
{
	if (t >= 'a'&& t <= 'z')
		return true;
	else return false;
}
Problem::Problem(string _content, int _rage)
{
	content = _content;
	rage = _rage;
	used=0;
	characters=0;								//总字符数
	lines=0;									//总行数
	words=0;									//总单词数
}
int Problem::classify(string lines_buf)
{
	int flag = 0;
	string word;
	int _length = lines_buf.length();
	characters += _length;
	for (int i = 0; i < _length; i++)
	{
		lines_buf[i] = tolower(lines_buf[i]);						//同一变成小写字母
		if (lines_buf[i] > ' ')flag = 1;							//判断是否为空字符
		if (_ischar(lines_buf[i]) == false)
		{
			if (_nonumber(word[0]) == true && _nonumber(word[1]) == true && _nonumber(word[2]) == true && _nonumber(word[3]) == true)
				//判断前四位是否为字母（该单词是否为单词）
			{
				if (_word.find(word) == _word.end())		//查找单词是否出现过
					_word[word] = 1;
				else _word[word]++;							//对应单词频率加一
			}
			word = "";
		}
		else word += lines_buf[i];
	}
	return flag;
}
void Problem::getrows()
{
	string line;
	char a;
	for (int i = 0; i < content.size(); i++)
	{
		a = content[i];
		line += a;
		if (a == '\n')
		{
			int flag = classify(line);
			if (flag != 0) lines++;
			line = "";
		}
	}
	int flag = classify(line);
	if (flag != 0) lines++;
	line = "";
}
//void Problem::display()
//{
//	for (auto my_Itr = _word.begin(); my_Itr != _word.end(); ++my_Itr) 
//	{
//		cout << my_Itr->first <<" "<< my_Itr->second<<endl;
//	}
//}
void Problem::_sort()
{
	for (int i = 0; i < rage; i++)
	{
		int max = 0;
		string word;
		for (auto my_Itr = _word.begin(); my_Itr != _word.end(); ++my_Itr)//遍历文本中出现的所有单词及其频率
		{
			if (my_Itr->second > max)
			{
				max = my_Itr->second;
				word = my_Itr->first;
			}
			if (i == 0)
				words += my_Itr->second;
		}
		_word[word] = -1;
		vocabulary tem;
		tem.word = word;
		tem.frequence = max;
		last_list.push_back(tem);
	}
}
void Problem::statistic()
{
	getrows();
	_sort();
	used = 1;
}
int Problem::getcharacters()
{
	if (used == 1)	return characters;
	else
	{
		statistic();
		return characters;
	}
}
int Problem::getlines()
{
	if (used == 1) return lines;
	else
	{
		statistic();
		return lines;
	}
}
int Problem::getwords()
{
	if (used == 1) return words;
	else
	{
		statistic();
		return words;
	}
}
vector<vocabulary> Problem::getmax_fre()
{
	if (used == 1) return last_list;
	else
	{
		statistic();
		return last_list;
	}
}

int get_characters(string infilepath, string outfilepath, int rage)
{
	File f(infilepath, outfilepath);
	Problem p(f.readfile());
	return p.getcharacters(); 
}
int get_words(string infilepath, string outfilepath, int rage)
{
	 File f(infilepath, outfilepath);
	 Problem p(f.readfile());
	 return  p.getwords();
}
vector<vocabulary> getmax_fre(string infilepath, string outfilepath, int rage)
{
	File f(infilepath, outfilepath);
	Problem p(f.readfile());
	return p.getmax_fre();
}