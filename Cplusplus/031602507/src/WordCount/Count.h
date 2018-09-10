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
	vector<pair<string, int> >  countTop10Word();
private:
	map<string, int> wordMap;
	vector<pair<string, int> > top10Word;
	inline bool isLetter(string::iterator it);
	inline bool isLetter(const char ch);
	inline bool isDigit(string::iterator it);
};



