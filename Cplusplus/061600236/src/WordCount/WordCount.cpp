#include "pch.h"
#include<iostream>
#include<string>
#include<stdio.h>
#include "CountChar.h"
#include "topten.h"
#include "CountWords.h"
#include "CountLines.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<regex>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
	return a.first > b.first;
}

int main(int argc, char** argv)
{
	//for (int i = 0; i < 10000; i++) //用于测试
	//{
	ofstream fileOutput;
	//char filename[105]= "test.txt";//用于测试
	fileOutput.open("result.txt", ios::app);
	fileOutput << "characters: " << CountChar(argv[1]) << endl;
	fileOutput << "lines: " << CountLines(argv[1]) << endl;
	fileOutput << "words: " << CountWords(argv[1]) << endl;
	topten(argv[1]);
	int count = 10;
	vector<pair<string, int> > vec;
	extern map<string, int> Map;
	for (auto u : Map) {
		vec.push_back(u);
	}
	sort(vec.begin(), vec.end(), cmp);
	for (auto u : vec)
	{
		if (count)
		{
			fileOutput << "<" << u.first << ">" << ":" << " " << u.second << endl;
			count--;
		}
		else break;
	}
	//}
	return 0;
}