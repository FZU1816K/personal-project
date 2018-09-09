#pragma once
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class Problem
{
public:
	Problem(string infilepath, string outfilepath);
	~Problem() {}
	int classify(string lines);						//传入字符串并将其中的单词分割出来返回值为传入是否能视为一行（返回1则为一行，行数加一）
	void get_line();								//从文件流中读取一行
	//void display();								//输出文本中所有单词的频率
	void _sort();									//查找出所有单词中频率最高的十个
	void result();									//将字符总数行数单词总数以及频率最高的十个单词写人文件
private:
	string _infilepath;								//读入文件名
	string _outfilepath;							//写入文件名
	ifstream ifs;									//读入文件流
	ofstream ofs;									//写人文件流
};