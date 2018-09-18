#include "pch.h"
#include "topten.h"

map<string, int> Map;
void topten(char *filename)//频率最高的十个单词 
{
	ifstream file;
	file.open(filename);
	string s;
	regex r("\\b[a-zA-Z]{4}[a-zA-Z0-9]*", regex::icase);
	while (file >> s) {
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] <= 'Z'&&s[i] >= 'A') s[i] = s[i] + 32;//干脆将所有的字母转换成小写 
		}
		smatch m;
		while (regex_search(s, m, r)) {
			Map[m[0]]++;
			s = m.suffix().str();
		}
	}
	file.close();
}