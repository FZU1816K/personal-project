#define _CRT_SECURE_NO_DEPRECATE
#include"CharCount.h"
#include"LineCount.h"
#include"WordCount.h"
#include"Frequency.h"


using namespace std;


int main(int argc, char** argv) {
	
	 
		char s[100];

		if (argv == NULL) {
			cout << "请输入文件名" << endl;
			return 0;
		}
		strcpy(s,argv[1]);
		charCount(s);
		frequency(s);
		lineCount(s);
		wordCount(s);
	
	
	return 0;
}