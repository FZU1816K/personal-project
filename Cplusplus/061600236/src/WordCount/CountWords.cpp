#include "pch.h"
#include "CountWords.h"
using namespace std;

int CountWords(char *filename)//ͳ�Ƶ����� 
{
	ifstream file;
	file.open(filename);
	string s;
	int sum = 0;
	regex r("\\b[a-zA-Z]{4}[a-zA-Z0-9]*", regex::icase);
	while (file >> s) {
		smatch m;
		while (regex_search(s, m, r)) {//ƥ�����������ʽ�ĵ��� 
			sum++;
			s = m.suffix().str();
		}
	}
	file.close();

	return sum;
}