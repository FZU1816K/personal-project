#include "FileRead.h"
#include <iostream>
#include <algorithm>

/*使文件流和目标文件建立链接*/
FileRead::FileRead(string filePath) {
	readFile.open(filePath, ios::in);
	if (!readFile) {
		cerr << filePath << "文件不存在！" << endl;
		exit(1);
	}
	lineNum = 0;
	wordNum = 0;
	crtNum = 0;
}

FileRead::~FileRead() {
	readFile.close();
}

/*遍历文件中的内容求字符数和行数*/
void FileRead::crtCount() {
	readFile.clear(ios::goodbit);
	readFile.seekg(ios::beg);//每次从头读取文件
	char c;
	int _lineNum = 0;
	int _crtNum = 0;
	int flag = 0;
	readFile >> noskipws;//不忽略空格
	while (readFile.get(c)) {
		_crtNum++;
		if (c != '\n' && c != ' ' && flag == 0) flag++;
		else if (c == '\n' && flag != 0) {
			_lineNum++;
			flag = 0;
		}
	}
	if (flag != 0) _lineNum++;

	/*将所求的字符数和行数保存到相应对象中*/
	crtNum = _crtNum;
	lineNum = _lineNum;
}

/*遍历文件求符合题意的单词总数并将单词及其出现次数保存到unorder_map类型的容器中*/
void FileRead::wordCount() {
	readFile.clear(ios::goodbit);
	readFile.seekg(0, ios::beg);//每次从头读取文件
	int _wordNum = 0;
	int alpLength = 0;
	int start = 0;//用于分割单词
	char str[100];
	string word;//暂时存储单词

	char c;
	readFile >> noskipws;
	while (readFile.get(c)) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			if ((c >= '0' && c <= '9') && (alpLength < 4)) {
				alpLength = 0;
				start = 0;
				continue;
			}
			else if (!(c >= '0' && c <= '9')) {
				if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
				alpLength++;
			}
			str[start++] = c;
		}
		else if (start > 3) {//遇到分隔符且单词以四个以上字母开头时符合题意
			_wordNum++;			
			//cout << alpLength << ", " << start << "   ";		
			alpLength = 0;
			str[start] = 0;
			start = 0;
			word = str;
			itor = wordMap.find(word);
			if (itor != wordMap.end()) {
				(itor->second)++;
			}
			else {
				wordMap[word] = 1;
			}
			//---------------------------------------------------------------------------
			//cout << word << endl;
		}
		else {
			alpLength = 0;
			start = 0;
		}
	}
	if (start > 3) {//文件末尾的单词无法进入之前的while循环需要单独判断
		_wordNum++;
		str[start] = 0;
		start = 0;
		word = str;
		itor = wordMap.find(word);
		if (itor != wordMap.end()) {
			(itor->second)++;
		}
		else {
			wordMap[word] = 1;
		}
	}

	wordNum = _wordNum;
}

/*将单词按要求排序后保存到orderWord容器中*/
void FileRead::wordPair() {
	/*通过迭代器将map中的pair数据复制到vector中*/
	for (itor = wordMap.begin(); itor != wordMap.end(); itor++) {
		orderWord.push_back(make_pair(itor->first, itor->second));
	}
	/*通过sort函数对vector中的单词按题目要求排序*/
	sort(orderWord.begin(), orderWord.end(), &wordPair_cmp);
}

int FileRead::getCrtNum() {
	if (crtNum == 0 && lineNum == 0) crtCount();
	return crtNum;
}

int FileRead::getLineNum() {
	if (crtNum == 0 && lineNum == 0) crtCount();
	return lineNum;
}

int FileRead::getWordNum() {
	if (wordMap.empty()) wordCount();
	return wordNum;
}

/*返回存放好有序的单词及其出现次数的容器*/
vector<pair<string, int>> FileRead::getOrderWord() {
	if (wordMap.empty()) wordCount();
	if (orderWord.empty()) wordPair();
	return orderWord;
}