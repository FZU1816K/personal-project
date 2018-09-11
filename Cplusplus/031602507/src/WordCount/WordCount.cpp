/********************************************************************************
* @File name: wc.cpp
* @Author: ChenYuXin
* @Version: 3.0
* @Date: 2018-09-11
* @Description: final version
********************************************************************************/


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include<map>
#include<algorithm>
#include"Count.h"	//封装所有的统计相关的功能
#include"FileIO.h"	//封装所有文件读写相关的功能
using namespace std;



int main(int argc, char *argv[]) 
{
	int lineCount = 0;			//行数
	int characterCount = 0;		//字符数
	int wordCount = 0;			//单词数
	
	Count count;
	string charBuf = FileIO::readChar(argc, argv);			//逐个字符读取文件，存入charBuf
	vector<string> linesBuf = FileIO::readLines(argc, argv);//逐行读取文件，存入linesBuf
	
	characterCount = count.countCharNum(charBuf);			//计算字符数
	lineCount = count.countLineNum(linesBuf);				//计算行数
	wordCount = count.countWordNum(linesBuf);				//计算单词数
	vector<pair<string, int> > top10Word = count.countTop10Word();	//统计出现频率最高的10个单词（有可能单词数没有10个）
	
	FileIO::outputToFile(characterCount, wordCount, lineCount, top10Word);	//将结果输出到文件

	//system("pause");
	return 0;
}