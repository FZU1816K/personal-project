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
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Statistics.h"

string GetFileNameFromArgs(int argc, char *argv[]) ;			 // 用于从命令行传入的参数中提取出输入文件名
bool ReadFileLines(string file_name, vector<string> &file_lines);//给定文件名，以vector<string>形式返回文件内容，每个元素代表一行
bool Output(int char_num, int word_num, int line_num, vector<map<string, int>::iterator> &top10wd,
			bool toConsole = true, bool toFile = true, string file_name = "result.txt");// 结果输出

int main(int argc, char *argv[])//int argc,char **argv   
{//argc参数长度,args参数数组
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
			Output(char_num, word_num, line_num, top10wd, true, true, "result.txt");
			//最后三个参数为：是否输出到控制台、是否输出到文件、文件名
		}
	}
	catch (const char* err)
	{
		cout << err << endl;
	}

	//system("pause");
	return 0;
}

string GetFileNameFromArgs(int argc, char *argv[]) // 用于从命令行传入的参数中提取出输入文件名
{
	if (argc == 1)//直接运行
	{
		return "input.txt";
	}
	else if (argc == 2)//通过命令行传参打开
	{
		return argv[1];
	}
	else
	{
		throw "参数过多，错误";
	}
}

bool ReadFileLines(string file_name, vector<string> &file_lines) //给定文件名，以vector<string>形式返回文件内容，每个元素代表一行
{
	ifstream ifs(file_name);
	if (!ifs)
	{
		throw "读取文件时打开文件异常";
		//return false;
	}
	else
	{
		string line_buf, str_low;
		char c;
		int _cnum = 0;
		while (true)//读取文件，按字符读入，拼装成行，存于file_lines中
		{
			c = ifs.get();
			if (c == EOF)
			{
				if (line_buf.size() > 0)
				{
					str_low.resize(line_buf.size());
					transform(line_buf.begin(), line_buf.end(), str_low.begin(), tolower);
					file_lines.push_back(str_low);
					//cout << str_low;
				}
				break;
			}
			line_buf += c;
			_cnum++;
			if (c == '\n')
			{
				str_low.resize(line_buf.size());
				transform(line_buf.begin(), line_buf.end(), str_low.begin(), tolower);
				file_lines.push_back(str_low);
				//cout << str_low;
				line_buf = "";
			}
		}
		//cout << "std char num:" << _cnum << endl;
		ifs.close();
		return true;
	}
}

bool Output(int char_num, int word_num, int line_num, vector<map<string, int>::iterator> &top10wd,
	bool toConsole, bool toFile, string file_name)// 结果输出。通过toConsole、toFile设置从控制台、文件输出。
{
	if (toConsole)// output to console
	{
		cout << "characters: " << char_num << endl;
		cout << "words: " << word_num << endl;
		cout << "lines: " << line_num << endl;
		for (unsigned int i = 0; i < top10wd.size(); i++)
		{
			cout << "<" << top10wd[i]->first << ">: " << top10wd[i]->second << endl;
		}
	}
	if (toFile)// output to file
	{
		ofstream ofs(file_name);
		if (!ofs)
		{
			throw "输出文件时打开文件异常";
			//return false;
		}
		else
		{
			ofs << "characters: " << char_num << endl;
			ofs << "words: " << word_num << endl;
			ofs << "lines: " << line_num << endl;
			for (unsigned int i = 0; i < top10wd.size(); i++)
			{
				ofs << "<" << top10wd[i]->first << ">: " << top10wd[i]->second << endl;
			}
			ofs.close();
		}
	}
	return true;
}
