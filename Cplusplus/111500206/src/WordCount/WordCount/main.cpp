#include<iostream>
#include<fstream>
#include"ArgumentParser.h"
#include"CountChar.h"
#include"CountLines.h"
#include"CountWords.h"
#include"WordFrequency.h"
using namespace std;

int main(int argc, char **argv)
{
	for (int i = 0; i < 10; i++) {
		int ret = Parse_Args(argc, argv);
		if (ret == -1) {
			return -1;
		}

		int numberOfChar = CountChar(argv[1]);
		int numberOfLines = CountLines(argv[1]);
		int numberOfWords = CountWords(argv[1]);

		cout << "In this file:" << endl;
		cout << "Number of characters: " << numberOfChar << endl;
		cout << "Number of non-empty lines: " << numberOfLines << endl;
		cout << "Number of words: " << numberOfWords << endl;

		WordFrequency(argv[1]);
		cout << "Top 10 words: " << endl;
		TopTenWords();
	}
	return 0;
}