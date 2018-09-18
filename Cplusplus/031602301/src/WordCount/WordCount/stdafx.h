#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<regex>
#include<list>
using namespace std;
typedef list<string> List;

//保持单词即其出现个数的类
class countWord
{
public:
	string name;
	int count;
	bool operator < (countWord& w1)//重载<运算符
	{
		return count > w1.count;
	}
};
typedef list<countWord> Wordlist;
//文件类，实现各项关于文件的操作
class File
{
public:
	File();
	void ShuRufile(string filename);
	void ShuChufile();
	void Wordscount(string filename);
private:
	int characters;
	int wordscount;
	int lines;
	List words;
	Wordlist words_count;
};
#pragma once
