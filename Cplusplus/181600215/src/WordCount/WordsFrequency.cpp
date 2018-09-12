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
	regex rx("\\b[a-zA-Z]{4}[a-zA-Z0-9]*");//�������ĸ�Ӣ����ĸ��ͷ
	while (getline(file, str)) {
		smatch m;
		while (regex_search(str, m, rx)) {
			string s = m[0];
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] >= 'A'&&s[i] <= 'Z') s[i] += 32;//��дתСд
			}
			M[s]++;//��ת����Сд����Ч���ʴ��map��
			str = m.suffix().str();
		}
	}
	file.close();
	for (auto x : M) {
		ans.push_back(x);
	}
	sort(ans.begin(), ans.end(), cmp);//����
	int count = 10;
	//�����Ƶ��ߵ�10������
	ofstream fout("result.txt");
	for (auto x : ans) {
		if (!count) break;
		cout <<"<"<< x.first<<">: " << " " << x.second << endl;//�������Ļ
		fout << "<" << x.first << ">: " << " " << x.second << endl;//������ļ�
		count--;
	}
	fout.close();
	M.clear();
	ans.clear();
}