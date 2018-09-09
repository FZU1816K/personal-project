// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include"problem.h"
#include"File.h"
using namespace std;


int main(int argc, char *argv[])//主函数参数 argc表示个数 argv为参数数组地址
{
	string infilepath;
	if (argc == 2)				//判断主函数参数是否为两个
		infilepath = argv[1];
	else
		cin >> infilepath;

	File f(infilepath, "result.txt");
	Problem p(f.readfile(), 10);
	f.DrawText(p.getcharacters(), p.getwords(), p.getlines(), p.getmax_fre());
	system("pause");
	return 0;
}