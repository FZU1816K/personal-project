#include<iostream>
#include<fstream>
#include"ArgumentParser.h"
#include"CountChar.h"
#include"CountLines.h"
#include"CountWords.h"
using namespace std;

int main(int argc, char **argv)
{
	int ret = Parse_Args(argc, argv);
	if (ret == -1) {
		return -1;
	}
	
	int numberOfChar;
	int numberOfLines;
	int numberOfWords;
	numberOfChar = CountChar(argv[1]);
	numberOfLines = CountLines(argv[1]);
	numberOfWords = CountWords(argv[1]);

	cout << "number of characters: "<<numberOfChar << endl;
	cout << "number of non-empty lines: "<< numberOfLines << endl;
	cout << "number of words: "<< numberOfWords << endl;
	return 0;
}