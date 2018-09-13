#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "check.h"
#include "CountFrequence.h"
#include "CountWords.h"
using namespace std;
Check mycheck;
Frequence myfrequence;
int word_count = 0;
unordered_map<string, int> Word::count_Word(string fname, unordered_map<string, int> strMap)
{
	string str, strfile;
	fstream file(fname);
	while (getline(file, str))
	{
		strfile.append(str);
		strfile.append(" ");
		str.clear();
	}
	for (int i = 0; i < strfile.length(); i++)
	{
		if (!mycheck.check_isVal(strfile[i]))
			strfile[i] = ' ';			 //符号位替换成为空格
	}
	transform(strfile.begin(), strfile.end(), strfile.begin(), ::tolower);
	istringstream stream(strfile);
	string word;
	while (stream >> word)
	{
		if (mycheck.check(word))
		{
			strMap = myfrequence.count_Frequency(word, strMap);
		}
	}
	return strMap;
	//unordered_map<string, int>::const_iterator it;
	//for (it = strMap.begin(); it != strMap.end(); ++it)
	//{
	//	//cout << it->first << "：" << it->second << endl;
	//	word_count++;
	//}
	//return word_count;
}