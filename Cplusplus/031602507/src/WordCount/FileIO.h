#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
using namespace std;

class FileIO
{
public:
	static string readChar(int argc, char *argv[]);
	static vector<string> readLines(int argc, char *argv[]);
	static void outputToFile(int characterCount, int lineCount, int wordCount, vector<pair<string, int> > &top10Word);
private:
	static string getFileName(int argc, char *argv[]);
};