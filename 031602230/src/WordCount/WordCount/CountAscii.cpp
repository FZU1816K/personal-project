#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "CountAscii.h"
using namespace std;
int Ascii::countAscii(string pth)			//计算总字符数
{
	fstream f(pth);
	if (!f)
	{
		cout << "不存在这个文件或者文件未打开，请重新输入！" << endl;
		exit(0);
	}
	char c;
	int count = 0;
	while (f.get(c))count++;
	return count;
}
int Ascii::countLine(string pth)			//计算总行数
{
	string str;
	fstream f(pth);
	if (!f)
	{
		cout << "不存在这个文件或者文件未打开，请重新输入！" << endl;
		exit(0);
	}
	int line_count = 0;
	while (getline(f, str))
	{
		if (str != " " && str != "\t" && str != "\n")line_count++;
		else continue;
	}
	return line_count;
}