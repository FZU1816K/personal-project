#pragma once
#include<iostream>
#include<string>
using namespace std;
class Top_Ten											//前十个频率最高的单词一个Top_Ten的类
{
public:
	int number;
	string word;
	Top_Ten()
	{
		number = 0;
		word = "";
	};
	~Top_Ten()
	{}
	friend  ostream  &operator <<(ostream &os, const Top_Ten &stu);
};
ostream  &operator<<(ostream &os, const Top_Ten &top_ten);

bool Cmp(const Top_Ten& top1, const Top_Ten& top2);		//自定义比较函数;
/**
***		功能：sort函数对Top_Ten类排序时的自定义排序函数
***			  按照不同单词出现频数从大到小排序，频数一样
***			  时按照字典序排列
**/

bool Is_Engch(char ch);
/**
***		功能：判断字符是否是英文字母
**/

bool Is_Num(char ch);
/**
***		功能：判断字符是否是数字
**/
string Is_Word(string word);
/**
***		功能：判断字符串是否是所要求的格式的单词
**/
void Top_Tenwords(Top_Ten words[],char *filename);
/**
***		功能：找出频数前十的是个单词
**/