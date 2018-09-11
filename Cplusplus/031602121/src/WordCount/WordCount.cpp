#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cassert>
#include <algorithm>
#include "Dll1.h"
#pragma comment(lib, "Dll1.lib")
#include "CountChars.h"
#include "CountLines.h"
#include "CountWF.h"
#include "CountWords.h"
using namespace std;
int main(int argc, char **argv)
{
	ifstream in(argv[1]);          //  打开文件
	ofstream fout("result.txt");

	int WordNum = CountWords(argv[1]);
	int LineNum = CountLines(argv[1]);
	int CharNum = CountChars(argv[1]);
	fout << "characters：" << CharNum << endl << "words: " << WordNum << endl << "lines: " << LineNum << endl;
	fout.close();
	CountWF(argv[1],fout);
	getchar();
	getchar();
	return 0;
}