#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "wordc.h"
using namespace std;

bool isLett(char c);
bool isNum(char c);
bool isAlph(char c);
bool myFunc(const pair<string, int> &x, const pair<string, int> &y);
unordered_map<string, int> createMap(string str);
string strManage(string str);
int countLines(string str);
string readTxt(string str);
void wordCount(string str);
void writeTxt();

vector <pair<string, int>> vtMap;
int characters = 0, words = 0, lines;
Core core;

int main() {
	string strTxt;
	string txtName = "input.txt";
	strTxt = readTxt(txtName);
	wordCount(strTxt);
	writeTxt();
	return 0;
}

string readTxt(string txtName) {
	string strTxt;
	ifstream infile(txtName, ios::in | ios::_Nocreate);			//将文件流对象与文件连接起来 														 
	if (!infile) {													//若失败,则输出错误消息,并终止程序运行
		cerr << "open error!" << endl;
		exit(1);
	}
	char c;
	infile >> noskipws;												//不忽略空白符，也不忽略换行符
	while (!infile.eof()) {
		infile >> c;
		if (infile.fail())
			break;
		if (c >= 'A' && c <= 'Z')
			c += 32;
		strTxt = strTxt + c;
	}
	infile.close();													 //关闭文件输入流 
	return strTxt;
}

void wordCount(string str) {
	characters = core.countCnum(str);
	lines = countLines(str);
	words = core.countWnum(str);
	core.wordHigh(str);
}

void writeTxt() {
	ofstream outfile("result.txt", ios::out);
	if (!outfile) {
		cerr << "open error!" << endl;
		exit(1);
	}
	int t = 0;
	outfile << "characters: " << characters << endl;
	outfile << "words: " << words << endl;
	outfile << "lines: " << lines << endl;
	for (auto it = vtMap.begin(); it != vtMap.end(); ++it) {
		outfile << "<" << it->first << ">: " << it->second << endl;
		t++;
		if (t == 10) {
			break;
		}
	}
	outfile.close();
}

int Core::countCnum(string str) {
	return str.length();
}

int Core::countWnum(string str) {
	string strWords;
	stringstream strm(strManage(str));										//使用unordered_map容器存储<string,int>对
	while (strm >> strWords) {
		words++;
	}
	return words;
}

void  Core::wordHigh(string str) {
	unordered_map<string, int> strMap = createMap(str);
	for (auto it = strMap.begin(); it != strMap.end(); it++) {
		vtMap.push_back(make_pair(it->first, it->second));
	}
	sort(vtMap.begin(), vtMap.end(), myFunc);
}

string Core::txtTostr(string str) {
	return readTxt(str);
}

int countLines(string str) {
	int len = str.length(), t = 1;
	for (int i = 0; i < len; i++) {
		if (str[i] == '\n') {
			for (int j = i + 1; j < len; j++) {
				if (str[j] == ' ') {
					continue;
				}
				else if (str[j] == '\n') {
					break;
				}
				else if (str[j] != ' ') {
					t++;
					i = j;
					break;
				}
			}
		}
	}
	return t;
}

unordered_map<string, int> createMap(string str) {
	unordered_map<string, int> strMap;
	string strWords;
	stringstream strm(strManage(str));										//使用unordered_map容器存储<string,int>对
	while (strm >> strWords) {
		unordered_map<string, int>::iterator it = strMap.find(strWords);
		if (it == strMap.end()) {
			strMap.insert(unordered_map<string, int>::value_type(strWords, 1));
		}
		else {
			strMap[strWords]++;
		}
	}
	return strMap;
}

string strManage(string str) {
	int i, j, len;
	len = str.length();
	for (i = 0; i < len; i++) {								//若不是单词，置为空格
		if (isLett(str[i])) {									
			if (isLett(str[i+1]) && isLett(str[i+2]) && isLett(str[i+3])) {
				if (i == len - 4) {
					break;
				}
				else {
					for (j = i + 4; j < len; j++) {
						if (!isAlph(str[j])) {
							str[j] = ' ';
							i = j;
							break;
						}
					}
				}
			}
			else {
				for (j = i; j < len; j++) {
					if (isAlph(str[j])) {
						str[j] = ' ';
					}
					else {
						str[j] = ' ';
						i = j;
						break;
					}
				}
			}
		}
		else if (isNum(str[i])) {
			str[i] = ' ';
			for (j = i + 1; j < len; j++) {
				if (isAlph(str[j])) {
					str[j] = ' ';
				}
				else {
					str[j] = ' ';
					i = j;
					break;
				}
			}
		}
		else if (!isAlph(str[i])) {
			str[i] = ' ';
		}
		if (j == len) {
			break;
		}
	}
	return str;
}

bool isLett(char c) {
	if (c >= 'a' && c <= 'z')
		return true;
	else
		return false;
}
bool isNum(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

bool isAlph(char c) {
	if (isNum(c)|| isLett(c))
		return true;
	else
		return false;
}
bool myFunc(const pair<string, int> &x, const pair<string, int> &y) {
	if (x.second > y.second)
		return true;
	else if (x.second == y.second) {
		if (x.first < y.first)
			return true;
		else
			return false;
	}
	else if (x.second < y.second)
		return false;
}