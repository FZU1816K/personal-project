/********************************************************************************
* @File name: wc.cpp
* @Author: ChenYuXin
* @Version: 2.1
* @Date: 2018-09-11
* @Description: Module Wrapping
********************************************************************************/


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include<map>
#include<algorithm>
#include"Count.h"
#include"FileIO.h"
using namespace std;



int main(int argc, char *argv[]) 
{
	int lineCount = 0;     
	int characterCount = 0;
	int wordCount = 0;     
	
	Count count;
	string charBuf = FileIO::readChar(argc, argv);
	vector<string> linesBuf = FileIO::readLines(argc, argv);
	
	characterCount = count.countCharNum(charBuf);
	lineCount = count.countLineNum(linesBuf);
	wordCount = count.countWordNum(linesBuf);
	vector<pair<string, int> > top10Word = count.countTop10Word();
	
	FileIO::outputToFile(characterCount, wordCount, lineCount, top10Word);

	//system("pause");
	return 0;
}