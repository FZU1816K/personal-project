#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cassert>
#include <algorithm>
#include "Dll1.h"
using namespace std;

int main(int argc,char **argv)
{
	ifstream in(argv[1]);          //  ���ļ�
	
	int WordNum = CountWords(argv[1]);
	int LineNum = CountLines(argv[1]);
	int CharNum = CountChars(argv[1]);
	cout << "characters��" << CharNum << endl << "words: " << WordNum << endl << "lines: "<< LineNum << endl;
	CountWF(argv[1]);
	return 0;
}