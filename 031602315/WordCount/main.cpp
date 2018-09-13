#include <fstream>     
#include <iostream>     
#include<algorithm>
#include<string>
#include"CountChar.h"
#include"CountLines.h"
#include"CountWordnumber.h"
#include"TenFrequency.h"
//extern vector<pair<string, int>> word;
//extern vector<pair<string, int>>::iterator vit;
//extern map<string, int> mCountMap;
using namespace std;
int main(int argc, const char* argv[])
{
	for (int i = 1; i < argc; i++) {
		ifstream file;
		file.open(argv[i], ios::in);
		if (!file) {
			cout << "无法打开文件\n";
			return -1;
		}
		file.close();
		vector<pair<string, int>> word;
		vector<pair<string, int>>::iterator vit;
		string mInputFileName = argv[i];
		int sum = CountChar(mInputFileName);
		cout << "characters:" << sum << endl;
		int wordnum = CountWordnumber(mInputFileName);
		cout << "words:" << wordnum << endl;
		int lines = CountLines(mInputFileName);
		cout << "lines:" << lines << endl;
		TenFrequency(mInputFileName,word);
		///写入result.txt
		ofstream out("result.txt", ios::app);
		out << "characters:" << sum << endl;
		out << "words:" << wordnum << endl;
		out << "lines:" << lines << endl;
		int size = 10;
		if (word.size() < 10) {
			size = word.size();
			cout << "单词不超过10个" << endl;
		}
		for (vit = word.begin(); vit != word.begin() + size; vit++) {
		out << "["<<vit->first <<"]:"<< " " << vit->second << endl;
		}
		out.close();
	}

	system("pause");
	return 0;
}

