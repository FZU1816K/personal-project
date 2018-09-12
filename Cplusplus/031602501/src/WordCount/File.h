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
	int frequence[1] = {0};
	string word;
};
class File
{
public:
	File(string infilepath, string outfilepath="");
	~File() {}
	void OpenFile();
	string readfile();
	void DrawText(int characters, int words, int _lines, vector<vocabulary> _list);//将题目要求的写入到目标文件中
private:
	string _infilepath;								//读入文件名
	string _outfilepath;							//写入文件名
	ifstream ifs;									//读入文件流
	ofstream ofs;									//写人文件流
	string content;									//文件内容
};
string Parameters_judgment(int argc, char *argv[]);				//主函数参数判断函数
