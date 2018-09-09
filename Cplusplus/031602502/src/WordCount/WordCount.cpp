//---------------------------------------------------------------------------------------------
//程序功能：对文本文件文件中的单词的词频进行统计
//运行方式：直接运行exe或者用命令行传参打开(WordCount.exe input.txt)均可
//统计指标：
//		字符数(所有ascll字符，空格、水平制表符、换行符都算)
//		单词数(单词以不少于4个字母开头，后面可以跟上字母数字。单词以分隔符分割，不区分大小写)
//		分隔符(除了字母数字都是分隔符)
//		有效行数：任何包含非空白字符(ascll值大于32)的行
//		出现频率最高的10个单词。频率相同的单词，优先输出字典序靠前的单词。
//输入文件来自input.txt，输出至文件output.txt，输出均为小写。
//---------------------------------------------------------------------------------------------
#include "pch.h"
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Statistics.h"
#include "myIO.h"
using namespace myIO;

int main(int argc, char *argv[])//int argc,char **argv   
{
	for (unsigned int k = 0; k < 1; k++)
	{
		try {
			string file_name = GetFileNameFromArgs(argc, argv);
			vector<string> file_lines;

			if (ReadFileLines(file_name, file_lines))//若读取文件内容成功，就执行统计功能
			{
				Statistics stats(file_lines);
				int char_num = stats.getCharNumber();
				int word_num = stats.getWordNumber();
				int line_num = stats.getLineNumber();
				vector<map<string, int>::iterator> &top10wd = stats.getTopWords(10);
				Output(char_num, word_num, line_num, top10wd, false, true, "result.txt");
				//最后三个参数为：是否输出到控制台、是否输出到文件、文件名
			}
		}
		catch (const char* err)
		{
			cout << err << endl;
		}
	}
	//system("pause");
	return 0;
}