#include<iostream>
#include<fstream>
#include"ArgumentParser.h"
#include"CountChar.h"

using namespace std;

int main(int argc, char **argv)
{
	int ret = Parse_Args(argc, argv);
	if (ret == -1) {
		return -1;
	}
	
	int numberOfChar;

	numberOfChar = CountChar(argv[1]);

	cout << numberOfChar << endl;
	return 0;
}