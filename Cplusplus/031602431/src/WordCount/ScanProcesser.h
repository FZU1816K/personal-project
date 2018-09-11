#ifndef _SCANPROCESSER_
#define _SCANPROCESSER_

#include <map>
#include <string>
#include <sstream>

using namespace std;

class ScanProcesser{
public:
    ScanProcesser(map<string,int> * inStrMap):charNum(0), wordNum(0), lineNum(0), inWord(0),newLine(0) {
		strMap = inStrMap;
		ss = new stringstream();
	}
	~ScanProcesser() {
		delete ss;
	}

    int processChar(char c);
    int getCharNum(){
        return charNum;
    }
    int getWordNum(){
        return wordNum;
    }
    int getLineNum(){
        return lineNum;
    }

	map<string,int>* getStrMapPointer() {
		return strMap;
	}



private:
    int charNum;
    int wordNum;
    int lineNum;
    int inWord;// IN = 1, OUT = 0
	int newLine;// OLD = 1, NEW = 0;
	stringstream* ss;
    const int SPACE = ' ';
    const int LINESYM = '\n';
    const int TAB = '\t';
    const int LINKWORDSYM = '-';
	map<string, int>* strMap;
	int checkWordValid(string str);
};


#endif