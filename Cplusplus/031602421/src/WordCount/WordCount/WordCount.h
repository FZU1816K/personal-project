#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl
typedef map<string, int> si_map;
class WordCounts{
	public:
	map<string, int>mp;
	bool judge(string str);//统计每个单词的出现频率
	bool get(string str, int & num);//拆分字符串+计算单词个数
	void work(string file_name,string fout_name);//读取文件+并将结果放入output文件
	void output(string file_name);
};
struct Word {///利用结构体排序
	string word;
	int num;
	bool operator < (const Word & a) const {
		if (num == a.num) return word < a.word;
		else return num > a.num;
	}
};