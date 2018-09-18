#include "FileRead.h"
#include <vector>
#include <iostream>

using namespace std;

#define WRITING_FILE "result.txt"
#define ORDER_WORD vector<pair<string, int>>

int main(int argc, char * argv[]) {
	string reading_flie;
	if (argc == 2) {
		reading_flie = argv[1];
	}
	else {									//�����в������ݴ���
		cerr << "�����в�����ʽ����" << endl;
		exit(1);
	}
	int i = 0;
	FileRead fileRead(reading_flie);
	ofstream fileWrite(WRITING_FILE, ios::out | ios::trunc);
	int crtNum = fileRead.getCrtNum();
	int lineNum = fileRead.getLineNum();
	int wordNum = fileRead.getWordNum();
	ORDER_WORD orderWord = fileRead.getOrderWord();
	ORDER_WORD::iterator outItor;
	if (!fileWrite) {										//�쳣����
		cerr << WRITING_FILE << "�ļ�д��ʧ��!" << endl;
		exit(1);											//�ڵ�Ԫ����ʱΪ��֤���Բ��ж��轫��ע��
	}
	fileWrite << "characters: " << crtNum << endl;
	fileWrite << "words: " << wordNum << endl;
	fileWrite << "lines: " << lineNum << endl;
	outItor = orderWord.begin();
	for (i = 0; i < 10 && outItor != orderWord.end(); i++, outItor++) {
		fileWrite << "<" << outItor->first << ">" << ": " << outItor->second << endl;
	}
	fileWrite.close();
	return 0;
}