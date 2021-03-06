#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool check_isChar(char s1)
{
	if ((s1 >= 'a'&&s1 <= 'z') || (s1 >= 'A'&&s1 <= 'Z'))return true;
	else return false;
}
bool check_isVal(char s1)
{
	if ((s1 >= 'a'&&s1 <= 'z') || (s1 >= 'A'&&s1 <= 'Z') || (s1 >= '0'&&s1 <= '9'))return true;
	else return false;
}
bool check(string str)
{
	if (str.length() <= 3)return false;
	if (!(check_isChar(str[0]) && check_isChar(str[1]) && check_isChar(str[2]) && check_isChar(str[3])))return false;
	for (int i = 4; i < str.length(); i++)
	{
		if (!check_isVal(str[i]))return false;
	}
	return true;  
}
int count_Ascii(string pth)			//计算总字符数
{
	fstream f(pth);
	char c;
	int count = 0;
	while (f.get(c))count++;
	return count;
}
int count_Line(string pth)			//计算总行数
{
	string str;
	fstream f(pth);
	int line_count = 0;
	while (getline(f, str))
	{
		if (str != "")line_count++;
		else continue;
	}
	return line_count;
}
unordered_map<string, int> strMap;  //保存的结果
void countWord(string strTmp)
{
	unordered_map<string, int>::iterator it = strMap.find(strTmp);
	if (it == strMap.end()) //strMap中如果不存在当前单词则插入一个新键值对，出现频率为1
	{
		strMap.insert(unordered_map<string, int>::value_type(strTmp, 1));
	}
	else                   //如果存在则出现频率+1
		strMap[strTmp]++;
}

int main()
{
	ifstream myfile("配置hpl.txt");
	string str, strfile;
	int line_count = 0;
	int word_count = 0;
	int allcount = 0;
	line_count = count_Line("配置hpl.txt");
	allcount = count_Ascii("配置hpl.txt");
	while (getline(myfile, str))
	{
		strfile.append(str);
		strfile.append(" ");
		str.clear();
	}
	for (int i = 0; i < strfile.length(); i++)
	{
		if (!check_isVal(strfile[i]))
			strfile[i] = ' ';			 //符号位替换成为空格
	}
	transform(strfile.begin(), strfile.end(), strfile.begin(), ::tolower);
	istringstream stream(strfile);
	string word;
	while (stream >> word)
	{
		if (check(word))
		{
			countWord(word);
		}
	}
	unordered_map<string, int>::const_iterator it;
	for (it = strMap.begin(); it != strMap.end(); ++it)
	{
		cout << it->first << "：" << it->second << endl;
		word_count++; 
	}
	cout << endl;
	cout << "单词总数：" << word_count << endl;
	cout << "总行数：" << line_count << endl;
	cout << "总字符数：" << allcount << endl;
	//map <string, int> mapStudent;
	//map <string, int> ::iterator it = mapStudent.find("student_one");
	//if (it != mapStudent.end())
	//{
	//	it->second++;
	//	cout << it->second << endl;
	//}
	//else
	//{
	//	mapStudent.insert(map<string, int>::value_type("student_one", 1));
	//}
	//it = mapStudent.find("student_one");
	//if (it != mapStudent.end())
	//{
	//	it->second++;
	//	cout << it->second << endl;
	//}


	return 0;
}



