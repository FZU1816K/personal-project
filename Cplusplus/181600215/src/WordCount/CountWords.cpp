#include "stdafx.h"
#include "CountWords.h"

int CountWords(char *filename)
{
	ifstream fin(filename);
	string str;
	int count = 0;
	regex rx("\\b[a-zA-Z]{4}[a-zA-Z0-9]*"); //�������ĸ�Ӣ����ĸ��ͷ
	while (fin >> str) {
		if (regex_match(str, rx))
			count++;
	}

	return count;
}