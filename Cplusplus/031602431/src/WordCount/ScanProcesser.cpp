#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "ScanProcesser.h"
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

const int IN = 1;
const int OUT = 0;
const int NEW = 0;
const int OLD = 1;

string nowWord;

int ScanProcesser::processChar(char c){

	if (c == EOF) {
		if (newLine == OLD)
			lineNum++;
	}
	else {
		if (isascii(c))
			charNum++;
		else {
			c = TAB;
		}
	}

	if (c == LINESYM) {
		if (newLine == OLD) {
			newLine = NEW;
			lineNum++;
		}
	}
	else {
		if (newLine == NEW) {
			if (!(c == SPACE || c == TAB))
				newLine = OLD;
		}
	}
	
	if (!(isalnum(c))){
		if (inWord == IN) {
			*ss >> nowWord;
			if (checkWordValid(nowWord)) {
				(*strMap)[nowWord]++;
				wordNumTotal++;
			}
			inWord = OUT;
			ss->clear();
			ss->str("");
			nowWord.clear();
		}
		else;
	}
	else if (isalnum(c)){
		if (isalpha(c))
			c = tolower(c);
		if (inWord == IN);
		else{
			inWord = IN;
		}
		*ss << c;
	}
	else;

	wordNum = strMap->size();
	return 0;
}

int ScanProcesser::checkWordValid(string str){
	unsigned int preCharCounts = 0;
	while (preCharCounts < str.length() && isalpha(str[preCharCounts]))
		preCharCounts++;
	if (preCharCounts >= 4)
		return 1;//True
	else {
		return 0;//False
	}
}


struct cmp {
	bool operator() (pair<int, string> a, pair<int, string> b) {
		if (a.first < b.first) {
			return 1;
		}
		else if (a.first == b.first) {
			return a.second > b.second;
		}
		return 0;
	}
};

int ScanProcesser::processTop10Words() {
	map<string, int>::iterator iter;
	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;

	iter = strMap->begin();

	while (iter != strMap->end())
	{
		que.push(make_pair(iter->second, iter->first));
		iter++;
	}
	for (int i = 0; i < 10 && i < wordNum; i++) {
		if (!que.empty()) {
			pair<int, string> wordPair = que.top();
			que.pop();
			top10Words[i] = wordPair.second;
			top10WordsCount[i] = wordPair.first;
		}
	}
	return 0;
}