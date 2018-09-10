#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <regex>
#include "CountChars.h"
#include "CountWords.h"
#include "WordFrequency.h"
using namespace std;
int main(int argc, char* argv[])
{
	int lines = 0;
	int chars = CountChars(argv[1]);
	int words = CountWords(argv[1]);
	string temp;
	ifstream inFile(argv[1]);
	while (getline(inFile, temp)) {
		if (temp != "")
			lines++;
	}
	cout << "characters:" << chars << endl;
	cout << "words:" << words << endl;
	cout << "lines:" << lines << endl;
	WordFrequency(argv[1]);
	return 0;
}