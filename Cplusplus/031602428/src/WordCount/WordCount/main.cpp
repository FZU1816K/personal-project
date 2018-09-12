#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <regex>
#include "CountChars.h"
#include "CountWords.h"
#include "WordFrequency.h"
using namespace std;

int ExceptionJudge(int argc, char* argv[]) {
	if (argc == 1)	printf("It is short of filename!\n");
	else if (argc > 2)	printf("Too many parametes!\n");
	else {
		char* file = argv[1];
		int len = strlen(file);
		if (len < 4) {
			printf("The file name entered is in an incorrect format!\n");
			return -1;
		}
		else if (file[len - 1] == 't' && file[len - 2] == 'x' && file[len - 3] == 't' && file[len - 4] == '.') {
			fstream fs(argv[1]);
			if (!fs.is_open())	printf("Fail to open file!\n");
			else return 0;
		}
		else printf("The file name entered is in an incorrect format!\n");
	}
	return -1;
}

int main(int argc, char* argv[])
{
	if (ExceptionJudge(argc, argv) == -1)	return -1;
	int lines = 0;
	int chars = CountChars(argv[1]);
	int words = CountWords(argv[1]);
	string temp;
	ifstream inFile(argv[1]);
	while (getline(inFile, temp)) {
		if (temp != "")
			lines++;
	}
	ofstream outFile;
	outFile.open("result.txt", ios::out);
	outFile << "characters:" << chars << endl;
	outFile << "words:" << words << endl;
	outFile << "lines:" << lines << endl;
	outFile.close();
	WordFrequency(argv[1]);
	return 0;
}