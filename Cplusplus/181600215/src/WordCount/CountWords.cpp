#include "stdafx.h"
#include "CountWords.h"

int CountWords(char *filename)
{
	ifstream fin(filename);
	string str;
	int count = 0;
	regex rx("\\b[a-zA-Z]{4}[a-zA-Z0-9]*"); //至少以四个英文字母开头
	while (fin >> str) {
		if (regex_match(str, rx))
			count++;
	}

	return count;
}