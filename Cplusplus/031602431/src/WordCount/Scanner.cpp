#define _CRT_SECURE_NO_WARNINGS 

#include "Scanner.h"
#include "ScanProcesser.h"
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


Scanner::Scanner(std::string inFileName, ScanProcesser* inProcesser)
	:processer(inProcesser) {

	file = fopen(inFileName.c_str(), "r");
	if (file == NULL) {
		perror("File error");
	}
	else {
		;
	}

}

int Scanner::scan() {
	// scan the file ,get the attributes
	char peekChar;
	while ((peekChar = fgetc(file)) != EOF) {
		processer->processChar(peekChar);
	}
	if (peekChar == EOF) {
		processer->processChar(EOF);
	}

	return 0;
}
