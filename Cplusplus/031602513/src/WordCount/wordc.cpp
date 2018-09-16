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

int main(int argc, char* argv[]) {
	string strTxt, txtName;
	if (argc == 2) {
		txtName = argv[1];
	}
	else {
		cerr << "�����г��������������" << endl;
		exit(1);
	}
	strTxt = readTxt(txtName);
	wordCount(strTxt);
	writeTxt();
	return 0;
}

string readTxt(string txtName) {
	string strTxt;
	ifstream infile(txtName, ios::in | ios::_Nocreate);			//���ļ����������ļ��������� 														 
	if (!infile) {													//��ʧ��,�����������Ϣ,����ֹ��������
		cerr << "open error!" << endl;
		exit(1);
	}
	char c;
	infile >> noskipws;												//�����Կհ׷���Ҳ�����Ի��з�
	while (!infile.eof()) {
		infile >> c;
		if (infile.fail())
			break;
		if (c >= 'A' && c <= 'Z')
			c += 32;
		strTxt = strTxt + c;
	}
	infile.close();													 //�ر��ļ������� 
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
	for (auto it = vtMap.begin(); t<10 && it != vtMap.end(); ++it, t++) {
		outfile << "<" << it->first << ">: " << it->second << endl;
	}
	outfile.close();
}

int Core::countCnum(string str) {
	return str.length();
}

int Core::countWnum(string str) {
	string strWords;
	stringstream strm(strManage(str));										//ʹ��unordered_map�����洢<string,int>��
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
	stringstream strm(strManage(str));										//ʹ��unordered_map�����洢<string,int>��
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
	for (i = 0; i < len; i++) {								//�����ǵ��ʣ���Ϊ�ո�
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
	else
		return false;
}