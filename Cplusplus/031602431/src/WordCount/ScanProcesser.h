#ifndef _SCANPROCESSER_
#define _SCANPROCESSER_

#include <map>
#include <string>
#include <sstream>

using namespace std;

// to store the top10 words
struct Top10Words {
	string str[10];
	int count[10];
};


// This class process every character using processChar(char c)
class ScanProcesser{
public:
    ScanProcesser(map<string,int> * inStrMap):charNum(0), wordNum(0), lineNum(0), inWord(0),newLine(0),wordNumTotal(0) {
		strMap = inStrMap;
		ss = new stringstream();
		for (int i = 0; i < 10; i++) {
			top10Words[i] = string();
			top10WordsCount[i] = 0;
		}
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
	int getWordNumTotal() {
		return wordNumTotal;
	}

	map<string,int>* getStrMapPointer() {
		return strMap;
	}

	int processTop10Words();

	struct Top10Words getTop10words() {
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
    int charNum;
    int wordNum;
	int wordNumTotal;
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

	string top10Words[10];
	int top10WordsCount[10];
};


#endif