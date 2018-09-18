#include "FileRead.h"
#include <iostream>
#include <algorithm>

/*ʹ�ļ�����Ŀ���ļ���������*/
FileRead::FileRead(string filePath) {
	lineNum = 0;
	wordNum = 0;
	crtNum = 0;
	hasCountCrtAndLine = false;					//�ж��Ƿ�ͳ�ƹ��ַ���������
	hasCountWord = false;							//�ж��Ƿ�ͳ�ƹ�������
	readFile.open(filePath, ios::in);
	if (!readFile) {								//�쳣����
		hasReadFile = false;
		cerr << filePath << "�ļ������ڣ�" << endl;
		exit(1);									//�ڵ�Ԫ����ʱΪ��֤���Բ��ж��轫��ע��
	}
	hasCountCrtAndLine = false;						//�ж��Ƿ�ͳ�ƹ��ַ���������
	hasCountWord = false;							//�ж��Ƿ�ͳ�ƹ�������
	hasReadFile = true;
}

FileRead::~FileRead() {
	readFile.close();
}

/*�����ļ��е��������ַ���������*/
void FileRead::crtCount() {
	if (!hasReadFile) return;
	readFile.clear(ios::goodbit);
	readFile.seekg(ios::beg);//ÿ�δ�ͷ��ȡ�ļ�
	char c;
	int _lineNum = 0;
	int _crtNum = 0;
	int flag = 0;
	readFile >> noskipws;//�����Կո�
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
	/*��������ַ������������浽��Ӧ������*/
	crtNum = _crtNum;
	lineNum = _lineNum;
}

/*�����ļ����������ĵ��������������ʼ�����ִ������浽unorder_map���͵�������*/
void FileRead::wordCount() {
	if (!hasReadFile) return;
	readFile.clear(ios::goodbit);
	readFile.seekg(0, ios::beg);									//ÿ�δ�ͷ��ȡ�ļ�
	int _wordNum = 0;
	int alpLength = 0;
	int start = 0;													//���ڷָ��
	int flag = 0;													//��֤����ǰ����������
	char str[100];													//���㴦������
	string word;													//��ʱ�洢����
	char c;
	readFile >> noskipws;
	while (readFile.get(c)) {										//whileѭ����ʾ�����ļ�
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {	//��ǰ�ַ�Ϊ��ĸ���ַ���
			if ((c >= '0' && c <= '9') && (alpLength < 4)) {			//��������������ǰ������ĸ<4���ʼ����ʶ����
				alpLength = 0;										//alpLength��ʾchar��������str�п�ͷ��������ĸ��Ŀ
				start = 0;											//strat��char��������str�г䵱�α������
				flag = 1;											//flag��ʼΪ0��1��ʾ��ǰ�ַ���ǰһ���ַ�������
				continue;
			}
			else if (!(c >= '0' && c <= '9')) {							//��ǰ�ַ�Ϊ��ĸ
				if (flag != 0 && alpLength < 4) continue;			//���ǰһ���ַ���������str���鿪ͷ������ĸ��Ŀ<4,��һ�����ǵ��ʣ�ֱ�ӽ�����һ�ζ��ַ�
				if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';		//��ĸͳһת��ΪСд��ĸ
				alpLength++;										//str���鿪ͷ��������ĸ��Ŀ
			}
			str[start++] = c;										//strΪchar���͵����飬�˴����ڴ����ַ�����������Ҫ����ַ������������α����
		}
		else if (alpLength > 3) {										//�����ָ�����str���鿪ͷ��ĸ��Ŀ>=4ʱΪҪ�󵥴�
			_wordNum++;												//������Ŀ++
			alpLength = 0;											//��ʼ�����ʿ�ͷ��ĸ��Ŀ
			str[start] = 0;											//�α�λ������ASCII������(�ַ�����/�ַ���������)
			start = 0;												//��ʼ���ַ������α�
			word = str;												//��str�����е������ַ�(������)תΪstring����(str[0->ԭstart])
			itor = wordMap.find(word);								
			if (itor != wordMap.end()) {							//������unordered_map���������Ƶ++
				(itor->second)++;
			}
			else {													//����δ���ֹ�����������Ҵ�Ƶ��Ϊ1
				wordMap[word] = 1;
			}
		}
		else {															//�����ָ�����str���鿪ͷ��������ĸ��Ŀ<4ʱ���ʲ�����Ҫ�󣬳�ʼ����ʶ����
			alpLength = 0;
			start = 0;
			if (flag != 0) flag = 0;
		}
	}
	if (start > 3) {//�ļ�ĩβ�ĵ����޷�����֮ǰ��whileѭ����Ҫ�����ж�
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
/*�����ʰ�Ҫ������󱣴浽orderWord������*/
void FileRead::wordPair() {
	/*ͨ����������unordered_map�е�pair���ݸ��Ƶ�vector��*/
	for (itor = wordMap.begin(); itor != wordMap.end(); itor++) {
		orderWord.push_back(make_pair(itor->first, itor->second));
	}
	int i = wordMap.size();								//i��֤��������С��10ʱ��������쳣
	if (i > 10)	i = 10;
	/*ͨ��paritial_sort������vector�еĵ��ʰ���ĿҪ������*/
	partial_sort(orderWord.begin(), orderWord.begin() + i, orderWord.end(), cmp());
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

/*���ش�ź�����ĵ��ʼ�����ִ���������*/
vector<pair<string, int>> FileRead::getOrderWord() {
	if (wordMap.empty()) wordCount();
	if (orderWord.empty()) wordPair();
	return orderWord;
}