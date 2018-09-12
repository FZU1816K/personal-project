#define _CRT_SECURE_NO_WARNINGS 

#ifndef _SCANNER_
#define _SCANNER_


#include <string>
#include <map>
#include "ScanProcesser.h"

using namespace std;

// to store the top10 words
struct Top10Words {
	string str[10];
	int count[10];
};

// This class will open the file and convert every character to ScanProcesser
// Then get result from ScanProcesser
class Scanner{
public:
	Scanner():file(NULL),processer(NULL) {}
    Scanner(string inFilename, ScanProcesser* inProcesser);
	~Scanner() {
		if (file != nullptr) {
			fclose(file);
		}
	}
	int scan();
	int processTop10Words();
	int getCharNum() {
		return charNum;
	}
	int getWordNum() {
		return wordNum;
	}
	int getLineNum() {
		return lineNum;
	}
	
	struct Top10Words getTop10words(){
		struct Top10Words tp;
		for (int i = 0; i < 10; i++) {
			tp.str[i] = string();
			tp.count[i] = 0;
		}
		for (int i = 0; i < 10 && i < wordNum; i++) {
			tp.str[i] = top10Words[i];
			tp.count[i] = top10WordsCount[i];
		}
		return tp;
	}


private:
	FILE* file;
	ScanProcesser* processer;
	map<string, int>* strMap;
	int charNum;
	int wordNum;
	int lineNum;
	string top10Words[10];
	int top10WordsCount[10];
};

#endif