#pragma once
#include "pch.h"
#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

struct vocabulary
{
	string word;
	int frequence;
};
class Problem
{
public:
	Problem(string _content, int _rage);
	~Problem() {}
	int classify(string lines_buf);					//传入字符串并将其中的单词分割出来返回值为传入是否能视为一行（返回1则为一行，行数加一）
	void getrows();									//计算传入文件的行数
	//void display();								//输出文本中所有单词的频率（测试用）
	void _sort();									//查找出所有单词中频率最高的十个
	void statistic();								//遍历文本内容计算
	int getcharacters();							//返回总字符数
	int getlines();									//返回总行数
	int getwords();									//返回总单词数							
	vector<vocabulary> getmax_fre();				//返回出现频率最高的十个单词
private:
	map<string, int> _word;							//存储单词及单词出现的频率
	vector<string>fqy;								//存储出现频率最高的十个单词
	int fre[10] = { 0 };							//存储出现频率最高的十个单词的频率
	vector<vocabulary> last_list;
	int used;
	string content;									//文本内容
	int characters;								//总字符数
	int lines;									//总行数
	int words ;									//总单词数
	int rage;									//输出频率前几（本题为十）可拓展
};

