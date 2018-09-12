#include "stdafx.h"
#include "WordsFrequency.h"
map<string, int> M;
vector < pair<string, int>> ans;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

void WordsFrequency(char *filename)
{
	ifstream file(filename);
	string str;
	regex rx("\\b[a-zA-Z]{4}[a-zA-Z0-9]*");//至少以四个英文字母开头
	while (getline(file, str)) {
		smatch m;
		while (regex_search(str, m, rx)) {
			string s = m[0];
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] >= 'A'&&s[i] <= 'Z') s[i] += 32;//大写转小写
			}
			M[s]++;//将转换成小写的有效单词存进map里
			str = m.suffix().str();
		}
	}
	file.close();
	for (auto x : M) {
		ans.push_back(x);
	}
	sort(ans.begin(), ans.end(), cmp);//排序
	int count = 10;
	//输出词频最高的10个单词
	ofstream fout("result.txt");
	for (auto x : ans) {
		if (!count) break;
		cout <<"<"<< x.first<<">: " << " " << x.second << endl;//输出到屏幕
		fout << "<" << x.first << ">: " << " " << x.second << endl;//输出到文件
		count--;
	}
	fout.close();
	M.clear();
	ans.clear();
}