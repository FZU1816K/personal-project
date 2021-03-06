#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include <algorithm>
#include "lower.h"
#include "judge.h"
#include "change.h"
using namespace std;
struct wd {
	int num;
	char* s;
	int flag = 1;
};
wd word[500] = { 0 };
wd word2[200] = { 0 };
int ans[200];
bool cmp(wd x, wd y)
{
	if (x.num > y.num)             return true;
	if (x.num < y.num)             return false;
	if (strcmp(x.s, y.s) < 0)    return true;
	return false;
}
int main(int argc,char **argv)
{
	int m = 0;
	int linenumber = 0;
	int Num = 0;
	int linenum = 0;
	string temp;
	if (argv[1] == NULL) {
		cout << "No input";
	}
	fstream file(argv[1]);
	if (!file) {
		printf("Unable to open");
	}
	char p[500];
	while (getline(file, temp)) {//每一行
		int n = 10;
		linenum = temp.size() + 1;
		linenumber++;
		Num = Num + linenum;
		lower(temp);
		change(temp, p);
		int l = 0;
		for (int y = 0; y < temp.size(); ) {
			int mm = m;
			if (p[y] == ' ' || p[y] == '.' || p[y] == '?' || p[y] == '!' || p[y] == ',' || p[y] == '"')
			{
				y++;
				continue;
			}
			else {//发现一个单词
				char *danci = (char*)malloc(sizeof(char) * 10);
				memset(danci, 0, sizeof(char) * 10);
				int k = 0;
				while ((p[y] >= 'a'&&p[y] <= 'z') || (p[y] >= '0'&&p[y] <= '9')) {
					danci[k] = p[y];
					k++; y++;
				}
				danci[k] = '\0';
				if (Judge(danci)) {
					word2[m].s = danci;
					word2[m].num = 0;
					m++;
				}
			}
			if (mm == m) {
				linenumber--;
			}
		}
	}
	file.close();
	for (int i = 0; i < m; i++) {
		for (int e = 0; e < m; e++) {
			if (!strcmp(word2[i].s, word2[e].s)) {
				word2[i].num++;
				if (e < i)
					word2[i].flag = 0;
			}
		}
	}
	int x = 0;
	int max = 0;
	for (int i = 0; i < m; i++) {//词 未排序 已计数
		if (word2[i].flag != 0) {
			word[x] = word2[i];
			x++;
		}
	}
	sort(word, word + x, cmp);
	ofstream fout("d://result.txt");
	fout << "characters:" << Num << endl;
	fout << "words:" << m << endl;
	fout << "lines:" << linenumber << endl;
	for (int i = 0; i < x; i++) {
		fout  << word[i].s << ":" << word[i].num << endl;  //测试
		if (i == 10)
			break;
	}
	fout.close();
	return 0;
}