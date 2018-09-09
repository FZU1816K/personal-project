#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>


namespace myIO
{
	string GetFileNameFromArgs(int argc, char *argv[]);			 // 用于从命令行传入的参数中提取出输入文件名
	bool ReadFileLines(string file_name, vector<string> &file_lines);//给定文件名，以vector<string>形式返回文件内容，每个元素代表一行
	bool Output(int char_num, int word_num, int line_num, vector<map<string, int>::iterator> &top10wd,
		bool toConsole = true, bool toFile = true, string file_name = "result.txt");// 结果输出
};