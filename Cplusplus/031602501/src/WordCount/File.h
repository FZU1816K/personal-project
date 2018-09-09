#pragma once
#include "pch.h"
#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"Problem.h"
using namespace std;

class File
{
public:
	File(string infilepath, string outfilepath);
	~File() {}
	string readfile();
	void DrawText(int characters, int words, int _lines, vector<vocabulary> _list);//将题目要求的写入到目标文件中
private:
	string _infilepath;								//读入文件名
	string _outfilepath;							//写入文件名
	ifstream ifs;									//读入文件流
	ofstream ofs;									//写人文件流
	string content;									//文件内容
};
