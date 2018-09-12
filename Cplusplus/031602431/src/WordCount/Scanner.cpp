#define _CRT_SECURE_NO_WARNINGS 

#include "Scanner.h"
#include "ScanProcesser.h"
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


Scanner::Scanner(std::string inFileName, ScanProcesser* inProcesser)
	:processer(inProcesser), charNum(0), wordNum(0), lineNum(0) {

	strMap = processer->getStrMapPointer();

	file = fopen(inFileName.c_str(), "r");
	if (file == NULL) {
		perror("File error");
	}
	else {
		;
	}
	for (int i = 0; i < 10; i++) {
		top10Words[i] = string();
		top10WordsCount[i] = 0;
	}
}

int Scanner::scan() {
	// scan the file ,get the attributes
	char peekChar;
	while ((peekChar = fgetc(file)) != EOF) {
		processer->processChar(peekChar);
	}
	if (peekChar == EOF) {
		processer->processChar(EOF);
	}

	charNum = processer->getCharNum();
	wordNum = processer->getWordNum();
	lineNum = processer->getLineNum();


	return 0;
}

struct cmp {
	bool operator() (pair<int,string> a, pair<int, string> b) {
		if (a.first < b.first) {
			return 1;
		}
		else if (a.first == b.first) {
			return a.second > b.second;
		}
		return 0;
	}
};

int Scanner::processTop10Words() {
	map<string, int>::iterator iter;
	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;

	iter = strMap->begin();

	while (iter != strMap->end())
	{
		que.push(make_pair(iter->second, iter->first));
		iter++;
	}
	for (int i = 0; i < 10 && i< wordNum ; i++) {
		if (!que.empty()) {
			pair<int, string> wordPair = que.top();
			que.pop();
			top10Words[i] = wordPair.second;
			top10WordsCount[i] = wordPair.first;
		}
	}
	return 0;
}