#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

class FileIO
{
public:
	static bool readChar(int argc, char *argv[], string &charBuf,vector<string> &linesBuf);
	static vector<string> readLines(int argc, char *argv[]);
	static void outputToFile(int characterCount, int lineCount, int wordCount, vector<map<string,int>::iterator> &top10Word);
private:
	static string getFileName(int argc, char *argv[]);
};