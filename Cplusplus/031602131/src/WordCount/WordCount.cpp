#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iterator>
#include <cctype>
#include <unordered_map>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include "WordCount.h"

using namespace std;
vector<pair<int, string> > vec2;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second; //按字典序从小到大排列 
}

bool cmpi(pair<int,string> a, pair<int, string> b)
{
	return a.first> b.first;
}

void MapSortOfValue(vector<pair<int, string> >& vec, map<string, int>& m)
{
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		vec.push_back(make_pair(it->second, it->first));
	sort(vec.begin(), vec.end(),cmpi);
}

/*
函数功能：判断是否为汉字
*/
int Cal::isChinese(char a,char b)
{
	int nRet = 0;
		//如果字符高位为1且下一字符高位也是1则有中文字符
	if ((a & 0x80) && (b & 0x80))
	{
		nRet = 1;
	}
	return nRet;
}
/*
函数功能：判断是否为分隔符
*/
int Cal::isSign(char c)
{
	int nRet = 1;
	if (((c > 47) && (c < 58)) || ((c > 64) && (c < 91)) || ((c > 96) && (c < 123)) || (c == 32))
	{
		nRet = 0;
	}
	return nRet;
}
/*
函数功能：判断是否为单词
*/
int Cal::isWord(string word)
{
	int i;
	for (i = 0; i < word.size(); i++)
	{
		if (i < 4)
		{
			if ((word[i] < 65 || word[i]>122) || (word[i] > 90 && word[i] < 97)) // A-Z，a-z
				return 0;
		}
		else
		{
			if ((word[i] < 48 || word[i]>122) || (word[i] > 57 && word[i] < 65) || (word[i] > 90 && word[i] < 97)) // A-Z，a-z,0-9
				return 0;
		}

	}
	if (i < 4)
		return 0;
	return 1;
}
/*
函数功能：统计字符数
*/
int Cal::CountChar(char *strr)
{
	ifstream infile(strr, ios::in); //以输入方式打开文件
		//判断是否打开成功
	if (!infile) {
		cout << "open error!" << endl;
		exit(1);
	}
	string s;
	int count = 0;
	while (getline(infile, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (isChinese(s[i],s[i+1])!=1)//不是汉字
			{
				count++;
			}
			else //是汉字，则跳过
			{
				i++;
			}
		}
		count++;
	}
	count--;
	cout << "characters:" << count << endl;
	infile.close();
	return count;
}
/*
函数功能:统计文件的单词总数
*/
int Cal::CountWord(char *strr)
{
	int count=0;
	ifstream infile(strr, ios::in); //以输入方式打开文件
	//判断是否打开成功
	if (!infile) {
		cout << "open error!" << endl;
		exit(1);
	}
	string s,str;
	while (getline(infile, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (isChinese(s[i],s[i+1]) == 1)//是汉字则跳过
			{
				i++;
			}
			else
			{
				if (isSign(s[i]) == 1)//是分隔符
				{
					s[i] = ' ';
				}
			}	
		}
		str.append(s);
		str.append(1,' ');
	}
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	stringstream ss(str);
	unordered_map<string, int> strMap;  //保存的结果
	string strTmp;
	while (ss >> strTmp)
	{
		if (isWord(strTmp) == 1)
		{
			count++;
		}
	}
	cout << "words:"<<count<<endl;
	infile.close();
	return count;
}
/*
函数功能:统计文件的有效行数
*/
int Cal::CountLine(char *strr)
{
	ifstream infile(strr, ios::in); //以输入方式打开文件
	//判断是否打开成功
	if (!infile) {
		cout << "open error!" << endl;
		exit(1);
	}
	string s;
	int count = 0;
	while (getline(infile, s))
	{
		count++;
	}
	cout << "lines:" << count << endl;
	infile.close();
	return count;
}

/*
函数功能：统计文件中各单词的出现次数
*/
int Cal::CountTime(char *strr)
{
	int count = 0, n = 0;
	ifstream infile(strr, ios::in); //以输入方式打开文件
	//判断是否打开成功
	if (!infile) {
		cout << "open error!" << endl;
		exit(1);
	}
	string s, str;
	while (getline(infile, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (isChinese(s[i], s[i + 1]) == 1)//是汉字则跳过
			{
				i++;
			}
			else
			{
				if (isSign(s[i]) == 1)//是分隔符
				{
					s[i] = ' ';
				}
			}
		}
		str.append(s);
		str.append(1, ' ');
	}
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	stringstream ss(str);
	map<string, int> strMap;  //保存的结果
	string strTmp;
	while (ss >> strTmp)
	{
		if (isWord(strTmp) == 1)
		{
			map<string, int>::iterator it = strMap.find(strTmp);
			if (it == strMap.end())
			{
				strMap.insert(map<string, int>::value_type(strTmp, 1));
			}
			else
				strMap[strTmp]++;
		}
	}
	vector<pair<int, string> > vec;
	MapSortOfValue(vec, strMap);
	for (vector<pair<int, string> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		n++;
		if (n <= 10)
		{
			vec2.push_back(make_pair(it->first, it->second));
		}
	}
	sort(vec.begin(), vec.end(), cmp);

	infile.close();
	return count;
}

int main(int argc, char* argv[])
{
	Cal a;
	int nc,nl,nw,nt;
	nc = a.CountChar(argv[1]);
	nw = a.CountWord(argv[1]);
	nl = a.CountLine(argv[1]);
	nt = a.CountTime(argv[1]);
	ofstream OutFile; 
	OutFile.open("result.txt");
	OutFile << "characters:" << nc << endl;
	OutFile << "words:" << nw << endl;
	OutFile << "lines:" << nl << endl;
	for (vector<pair<int, string> >::iterator it = vec2.begin(); it != vec2.end(); it++)
	{
		cout << "<" << it->second << ">:" << it->first << endl;
		OutFile << "<" << it->second << ">:" << it->first << endl;
	}
	OutFile.close();
	system("pause");
	return 0;
}