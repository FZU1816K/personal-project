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
	else {									//命令行参数传递错误
		cerr << "命令行参数格式错误" << endl;
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
	if (!fileWrite) {										//异常处理
		cerr << WRITING_FILE << "文件写入失败!" << endl;
		exit(1);											//在单元测试时为保证测试不中断需将其注释
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