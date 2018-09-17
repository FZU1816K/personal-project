#include "stdafx.h"
#include "CountWords.h"

int CountWords(char *filename)
{
	ifstream fin(filename);
	string str;
	int count = 0;
	regex rx("\\b[a-zA-Z]{4}[a-zA-Z0-9]*"); //单词至少以四个字母开头
	while (getline(fin, str)) {
		smatch m;
		while (regex_search(str, m, rx)) {
			string s = m[0];
			count++;
			str = m.suffix().str();
		}
	}

	return count;
}