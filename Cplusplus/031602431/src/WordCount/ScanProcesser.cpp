#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "ScanProcesser.h"

using namespace std;

const int IN = 1;
const int OUT = 0;
const int NEW = 0;
const int OLD = 1;
int ScanProcesser::processChar(char c){
	string nowWord;

	if (c == EOF) {
		lineNum++;
	}
	else {
		charNum++;
	}

	if (c == LINESYM) {
		if (newLine == OLD) {
			newLine = NEW;
			lineNum++;
		}
	}
	else {
		if (newLine == NEW) {
			newLine = OLD;
		}
	}
	

	if (c == SPACE || c == TAB || c == LINKWORDSYM || c == LINESYM || c==EOF ) {
		if (inWord == IN) {
			*ss >> nowWord;
			if (checkWordValid(nowWord)) {
				map<string, int>::iterator iter;

				iter = strMap->find(nowWord);

				if (iter != strMap->end()) {
					int count = (iter->second) + 1;
					strMap->erase(iter);
					strMap->insert(pair<string, int>(nowWord, count));
				}
				else {
					wordNum++;
					strMap->insert(pair<string, int>(nowWord, 1));
				}
			}
			inWord = OUT;
			delete ss;
			ss = new stringstream();
		}
		else;
	}
	else if (isalnum(c)){
		if (isalpha(c))
			c = tolower(c);
		string stest;
		if (inWord == IN);
		else{
			inWord = IN;
		}
		*ss << c;
	}
	else;
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