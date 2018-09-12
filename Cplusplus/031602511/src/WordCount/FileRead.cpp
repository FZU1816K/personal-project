#include "FileRead.h"
#include <iostream>
#include <algorithm>

/*使文件流和目标文件建立链接*/
FileRead::FileRead(string filePath) {
	lineNum = 0;
	wordNum = 0;
	crtNum = 0;
	hasCountCrtAndLine = false;					//判断是否统计过字符数和行数
	hasCountWord = false;							//判断是否统计过单词数
	readFile.open(filePath, ios::in);
	if (!readFile) {								//异常处理
		hasReadFile = false;
		cerr << filePath << "文件不存在！" << endl;
		exit(1);									//在单元测试时为保证测试不中断需将其注释
	}
	hasCountCrtAndLine = false;						//判断是否统计过字符数和行数
	hasCountWord = false;							//判断是否统计过单词数
	hasReadFile = true;
}

FileRead::~FileRead() {
	readFile.close();
}

/*遍历文件中的内容求字符数和行数*/
void FileRead::crtCount() {
	if (!hasReadFile) return;
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

	hasCountCrtAndLine = true;
	/*将所求的字符数和行数保存到相应对象中*/
	crtNum = _crtNum;
	lineNum = _lineNum;
}

/*遍历文件求符合题意的单词总数并将单词及其出现次数保存到unorder_map类型的容器中*/
void FileRead::wordCount() {
	if (!hasReadFile) return;
	readFile.clear(ios::goodbit);
	readFile.seekg(0, ios::beg);									//每次从头读取文件
	int _wordNum = 0;
	int alpLength = 0;
	int start = 0;													//用于分割单词
	int flag = 0;													//保证单词前不出现数字
	char str[100];													//方便处理数据
	string word;													//暂时存储单词
	char c;
	readFile >> noskipws;
	while (readFile.get(c)) {										//while循环表示遍历文件
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {	//当前字符为字母数字符号
			if ((c >= '0' && c <= '9') && (alpLength < 4)) {			//读到数字且数字前连续字母<4则初始化标识变量
				alpLength = 0;										//alpLength表示char类型数组str中开头的连续字母数目
				start = 0;											//strat在char类型数组str中充当游标的作用
				flag = 1;											//flag初始为0，1表示当前字符的前一个字符是数字
				continue;
			}
			else if (!(c >= '0' && c <= '9')) {							//当前字符为字母
				if (flag != 0 && alpLength < 4) continue;			//如果前一个字符是数字且str数组开头连续字母数目<4,则一定不是单词，直接进行下一次读字符
				if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';		//字母统一转化为小写字母
				alpLength++;										//str数组开头的连续字母数目
			}
			str[start++] = c;										//str为char类型的数组，此处用于处理字符串，将符合要求的字符存入数组且游标后移
		}
		else if (alpLength > 3) {										//遇到分隔符且str数组开头字母数目>=4时为要求单词
			_wordNum++;												//单词数目++
			alpLength = 0;											//初始化单词开头字母数目
			str[start] = 0;											//游标位的数组ASCII码置零(字符数组/字符串结束符)
			start = 0;												//初始化字符数组游标
			word = str;												//将str数组中的所有字符(即单词)转为string类型(str[0->原start])
			itor = wordMap.find(word);								
			if (itor != wordMap.end()) {							//单词在unordered_map容器中则词频++
				(itor->second)++;
			}
			else {													//单词未出现过则加入容器且词频设为1
				wordMap[word] = 1;
			}
		}
		else {															//遇到分隔符且str数组开头的连续字母数目<4时单词不符合要求，初始化标识变量
			alpLength = 0;
			start = 0;
			if (flag != 0) flag = 0;
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
	hasCountWord = true;
	wordNum = _wordNum;
}


bool cmp::operator()(pair<string, int> &a, pair<string, int> &b) {
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}
/*将单词按要求排序后保存到orderWord容器中*/
void FileRead::wordPair() {
	/*通过迭代器将unordered_map中的pair数据复制到vector中*/
	for (itor = wordMap.begin(); itor != wordMap.end(); itor++) {
		orderWord.push_back(make_pair(itor->first, itor->second));
	}
	/*通过paritial_sort函数对vector中的单词按题目要求排序*/
	partial_sort(orderWord.begin(), orderWord.begin() + 10, orderWord.end(), cmp());
}

int FileRead::getCrtNum() {
	if (!hasCountCrtAndLine) crtCount();
	return crtNum;
}

int FileRead::getLineNum() {
	if (!hasCountCrtAndLine) crtCount();
	return lineNum;
}

int FileRead::getWordNum() {
	if (!hasCountWord) wordCount();
	return wordNum;
}

/*返回存放好有序的单词及其出现次数的容器*/
vector<pair<string, int>> FileRead::getOrderWord() {
	if (wordMap.empty()) wordCount();
	if (orderWord.empty()) wordPair();
	return orderWord;
}