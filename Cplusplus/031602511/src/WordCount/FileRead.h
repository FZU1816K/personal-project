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
	int getLineNum();
	int getWordNum();
	int getCrtNum();
	vector<pair<string, int>> getOrderWord();//返回存放好有序的单词及其出现次数的容器
private:
	int lineNum;
	int wordNum;
	int crtNum;
	ifstream readFile;
	unordered_map<string, int> wordMap;//存放文件中符合要求的单词
	unordered_map<string, int>::iterator itor;
	vector<pair<string, int>> orderWord;//按序存放单词的容器
	void wordCount();//求文件单词数并存放文件中单词
	void crtCount();//求文件字符数及行数
	void wordPair();//将文件中单词按要求排序
	/*wordPair函数所需比较函数*/
	static bool wordPair_cmp(pair<string, int> a, pair<string, int> b);
};