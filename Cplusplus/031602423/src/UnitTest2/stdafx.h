// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

// 用于 CppUnitTest 的头文件
#include "CppUnitTest.h"
#include<iostream>
#include<string>
#include<map>
#include <fstream>
#include <algorithm>
#include<vector>
#include <assert.h>
using namespace std;
int character(char* path);
int word(char* path);
int isstring(string c);
string mytolower(string s);
void WordsFrequency(char* path);
int cmp(const pair<string, int>& x, const pair<string, int>& y);
vector<string> splitt(const string &s);
int main(int args, char* argv[]);
// TODO: 在此处引用程序需要的其他头文件
