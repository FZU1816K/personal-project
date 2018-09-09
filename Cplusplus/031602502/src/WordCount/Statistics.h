#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Statistics//统计类 封装了用于统计的方法
{
public:
	Statistics(vector<string> &file_lines);	//构造，文件内容按vector<string>传入
	~Statistics();							//析构
	inline bool isLetter(const char &c);	//判断给定字符是否为字母
	inline bool isNumber(const char &c);	//判断给定字符是否为数字
	int getCharNumber();					//获取字符个数。若尚未进行统计，会自动调用calc()
	int getWordNumber();					//获取字符个数。若尚未进行统计，会自动调用calc()
	int getLineNumber();					//获取字符个数。若尚未进行统计，会自动调用calc()
	vector<map<string, int>::iterator> &getTopWords(int top_num);	//获取出现次数排名前几的单词
	map<string, int> _getAllWords();		//获取整个字典的拷贝，仅用于调试。
private:
	void calc();							//统计功能，用于建立word map
	vector<string> &m_file_lines;
	map<string, int> m_wd_mp;
	vector<map<string, int>::iterator> m_top_words;
	int m_char_num;
	int m_word_num;
	int m_line_num;
	bool calculated;
};