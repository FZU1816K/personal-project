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
	try
	{
		string infilepath;
		infilepath = Parameters_judgment(argc,argv);
		File f(infilepath, "result.txt");
		f.OpenFile();
		Problem p(f.readfile());
		f.DrawText(p.getcharacters(), p.getwords(), p.getlines(), p.getmax_fre());
	}
	catch (string Err)
	{
		cout << Err << endl;
	}
	return 0;
}