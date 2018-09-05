#include<iostream>
#include<fstream>
#include"ArgumentParser.h"
#include"CountChar.h"
#include"CountLines.h"
using namespace std;

int main(int argc, char **argv)
{
	int ret = Parse_Args(argc, argv);
	if (ret == -1) {
		return -1;
	}
	
	int numberOfChar;
	int numberOfLines;
	numberOfChar = CountChar(argv[1]);
	numberOfLines = CountLines(argv[1]);

	cout << numberOfChar << endl;
	cout << numberOfLines << endl;

	return 0;
}