// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "WordCount.h"

bool WordCounts::judge(string str) {//判断是否符合条件+统计每个单词的出现次数
	int len = str.length();
	if (len < 4) return false;//长度小于4
	if ((str[0] <= 'Z'&&str[0] >= 'A') || (str[0] <= 'z'&&str[0] >= 'a')) {//开头不能是数字
		for (int i = 0; i < len; i++) {
			if (str[i] <= 'Z'&&str[i] >= 'A') str[i] = str[i] - 'A' + 'a';
		}
		mp[str]++;//存入map
		return true;
	}
	return false;
}

bool WordCounts::get(string str, int & num) {//对每行string进行分解+统计单词个数
	int len = str.length();
	int fg = 0;
	string neword = "";
	for (int i = 0; i < len; i++) {
		if (str[i] != '\n' && str[i] != ' ') fg = 1;
		if ((str[i] > 'Z' || str[i] < 'A') && (str[i] > 'z' || str[i] < 'a') && (str[i] > '9' || str[i] < '0')) {
			if (judge(neword)) num++;
			neword = "";
			continue;
		}
		else
		{
			neword += str[i];
		}
	}
	if (judge(neword))num++;
	return fg;
}
void WordCounts::work(string file_name,string fout_name) {
	ifstream fin(file_name, ios::in);
	if (!fin.is_open()) {
		cout << "打开 input 文件失败" << endl;
		exit(0);
	}
	ofstream fout(fout_name, ios::out);//将 ans 写入output文件
	if (!fout.is_open()) {
		cout << "打开 result 文件失败" << endl;
		exit(0);
	}
	int chnu = 0, words = 0, lines = 0;
	string tmp;
	int nucnt = 0;
	while (getline(fin, tmp)) {
		nucnt++;//
		chnu += tmp.length();//字符个数记录
		if(get(tmp, words))lines++;//分解每行字符串+判断是否为有效行数
	}
	si_map::iterator it;//利用迭代器遍历map
	vector<Word>w;
	for (it = mp.begin(); it != mp.end(); it++) {
		Word t;
		t.word = it->first; t.num = it->second;
		w.push_back(t);
	}
	sort(w.begin(), w.end());
	//读入output文件
	
	fout << "characters: " << chnu + nucnt << endl;///chun没有存取回车符
	fout << "words: " << words << endl;
	fout << "lines: " << lines << endl;
	int cnt = w.size();
	for (int i = 0; i < min(10, cnt); i++)
	{
		fout << "<" << w[i].word << ">: " << w[i].num << endl;
	}
	return;
}

void WordCounts::output(string file_name){
	
	ifstream fin(file_name, ios::in);
	if (!fin.is_open()) {
		cout << "未成功打开 reslut 文件" << endl;
		exit(-1);
	}
	string tmp;
	while (getline(fin, tmp)) {
		cout << tmp << endl;
	}
	return;
}
int main(int argc, char *argv[]){
	string file_name,fout_name;
	file_name = argv[1];//当直接用cmd运行exe文件时 
	//file_name = "input.txt";
	fout_name = "reslut.txt";
	WordCounts res;
	res.work(file_name,fout_name);
	res.output(fout_name);
	return 0;
}