#pragma once
#include <fstream>
#include <string> 
#include <unordered_map>
#include <vector>

using namespace std;

#define ORDER_WORD vector<pair<string, int>>

class FileRead
{
public:
	FileRead(string filePath);
	~FileRead();
	int getCrtNum();									//返回字符数
	int getLineNum();									//返回行数
	int getWordNum();									//返回单词总数
	vector<pair<string, int>> getOrderWord();			//返回存放好有序的单词及其出现次数的容器
private:
	int lineNum;
	int wordNum;
	int crtNum;
	bool hasCountCrtAndLine;					//判断是否统计过字符数和行数
	bool hasCountWord;							//判断是否统计过单词数
	bool hasReadFile;
	ifstream readFile;
	unordered_map<string, int> wordMap;					//存放文件中符合要求的单词
	unordered_map<string, int>::iterator itor;
	vector<pair<string, int>> orderWord;				//按序存放单词的容器

	void wordCount();									//统计文件单词数并存放文件中单词
	void crtCount();									//统计文件字符数及行数
	void wordPair();									//将文件中单词按要求排序
};

class cmp {
public:
	bool operator()(pair<string, int> &a, pair<string, int> &b);
};