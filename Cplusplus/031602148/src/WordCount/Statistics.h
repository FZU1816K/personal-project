#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

class Statistics
{
public:
	vector<int>a;//排序用
	map<string, int> word;//记录单词及词频
	void set(ifstream& in);//进行统计
	void display(ofstream& out);//输出统计结果
	int characters(ifstream& in);//统计字符数
	int	words(ifstream& in);//统计单词数
	int lines(ifstream& in);//统计行数
private:
	int cnum;//字符数
	int wnum;//单词数
	int lnum;//行数
};
