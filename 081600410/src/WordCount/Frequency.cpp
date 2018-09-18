#include"Frequency.h"
using namespace std;


void frequency(const char* file) {
	int number = 0;
	ifstream fin;
	ofstream fout;
	fout.open(".//result.txt", ios::app);
	fin.open(file);
	if (!fin) {
		cout << "The File cannot open." << endl;
	}
	string s;
	hash_map<string, int> wordList;
	while (true) {
		fin >> s;
		string tem = "";
		int len = s.length();

		int pre = -1;//记录本单词上一个字母的位置,初始为-1
		for (int i = 0; i < len; i++) {
			if ('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
			if (s[i] > 'z' || (s[i]<'a'&&s[i]>'9') || s[i] < '0') {
				if (i - pre > 4 && (s[pre + 1] <= 'z'&&s[pre + 1] >= 'a')) {
					for (int j = pre + 1; j < i; j++)
						tem += s[j];
					/*if (wordList[tem] == 0)*/ number++;
					wordList[tem]++;
					tem = "";
				}
				pre = i;
			}
			else if (i == len - 1 && i - pre >= 4 && (s[pre + 1] <= 'z'&&s[pre + 1] >= 'a')) {
				for (int j = pre + 1; j <= i; j++)
					tem += s[j];
				/*if (wordList[tem] == 0)*/ number++;
				wordList[tem]++;
				tem = "";
			}
		}
		if (fin.eof()) {
			break;
		}

	}
	fout << "words: " << number << endl;
	fin.close();
	fout.close();

}