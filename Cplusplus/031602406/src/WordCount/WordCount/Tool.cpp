#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cctype>
#include<regex>
#include<io.h>
#include<unordered_map>
#include<iterator>
#include "Tool.h"

using namespace std;

/*逐个字符读入文件内容*/
int Tool::CharCount(char* argv)
{
	ifstream file1;
	file1.open(argv);
	char c;
	int num = 0;
	while (!file1.eof())
	{
		file1 >> c;
		if (c >= 0 && c <= 127)
			num++;
	}
	file1.close();
	return num;

}

int Tool::LineCount(char* argv)
{
	int num = 0;
	ifstream file1;
	file1.open(argv);
	string str;
	while (!file1.eof())
	{
		getline(file1, str);
		if(str != "")
		num++;
	}
	file1.close();
	return num;
}

