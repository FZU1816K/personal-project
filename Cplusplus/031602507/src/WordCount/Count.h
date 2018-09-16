#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
class Count
{
public:
	int countCharNum(string &charBuf);
	int countWordNum(vector<string> &linesBuf);
	int countLineNum(vector<string> &linesBuf);
	vector<map<string,int>::iterator>  & countTop10Word();
private:
	map<string, int> wordMap;
	vector<map<string, int>::iterator> top10Word;
	inline bool isLetter(string::iterator it);
	inline bool isLetter(const char & ch);
	inline bool isDigit(string::iterator it);
	inline bool isDigit(const char & ch);
};



