#include "stdafx.h"
#include "WordsFrequency.h"
map<string, int> M;
vector < pair<string, int>> ans;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

void init()
{
	M.clear();
	ans.clear();
}

void WordsFreq(char *filename)
{
	ifstream file(filename);
	string str;
	regex rx("\\b[a-zA-Z]{4}[a-zA-Z0-9]*");
	while (getline(file, str)) {
		smatch m;
		while (regex_search(str, m, rx)) {
			string s = m[0];
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] >= 'A'&&s[i] <= 'Z') s[i] += 32;
			}
			M[s]++;
			str = m.suffix().str();
		}
	}
	file.close();
}

void TopTenWords(char *filename)
{
	for (auto x : M) {
		ans.push_back(x);
	}
	sort(ans.begin(), ans.end(), cmp);
	int count = 10;
	ofstream fout("result.txt", ios::app);
	for (auto x : ans) {
		if (!count) break;
		fout << "<" << x.first << ">: " << x.second << endl;
		count--;
	}
	fout.close();
}