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
	int ret = Parse_Args(argc, argv);
	if (ret == -1) {
		return -1;
	}

	int numberOfChar = CountChar(argv[1]);
	int numberOfLines = CountLines(argv[1]);
	int numberOfWords = CountWords(argv[1]);

	printf("In this file:\n");
	printf("Number of characters: %d\n", numberOfChar);
	printf("Number of non-empty lines: %d\n", numberOfLines);
	printf("Number of words: %d\n", numberOfWords);

	printf("Top 10 words:\n");
	WordFrequency(argv[1]);

	auto topTenWordList = TopTenWords();
	StandardOutput(topTenWordList);
	OutputToFile(topTenWordList);

	return 0;
}