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
	return a.second < b.second; //���ֵ����С�������� 
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
�������ܣ��ж��Ƿ�Ϊ����
*/
int Cal::isChinese(char a,char b)
{
	int nRet = 0;
		//����ַ���λΪ1����һ�ַ���λҲ��1���������ַ�
	if ((a & 0x80) && (b & 0x80))
	{
		nRet = 1;
	}
	return nRet;
}
/*
�������ܣ��ж��Ƿ�Ϊ�ָ���
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
�������ܣ��ж��Ƿ�Ϊ����
*/
int Cal::isWord(string word)
{
	int i;
	for (i = 0; i < word.size(); i++)
	{
		if (i < 4)
		{
			if ((word[i] < 65 || word[i]>122) || (word[i] > 90 && word[i] < 97)) // A-Z��a-z
				return 0;
		}
		else
		{
			if ((word[i] < 48 || word[i]>122) || (word[i] > 57 && word[i] < 65) || (word[i] > 90 && word[i] < 97)) // A-Z��a-z,0-9
				return 0;
		}

	}
	if (i < 4)
		return 0;
	return 1;
}
/*
�������ܣ�ͳ���ַ���
*/
int Cal::CountChar(char *strr)
{
	ifstream infile(strr, ios::in); //�����뷽ʽ���ļ�
		//�ж��Ƿ�򿪳ɹ�
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
			if (isChinese(s[i],s[i+1])!=1)//���Ǻ���
			{
				count++;
			}
			else //�Ǻ��֣�������
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
��������:ͳ���ļ��ĵ�������
*/
int Cal::CountWord(char *strr)
{
	int count=0;
	ifstream infile(strr, ios::in); //�����뷽ʽ���ļ�
	//�ж��Ƿ�򿪳ɹ�
	if (!infile) {
		cout << "open error!" << endl;
		exit(1);
	}
	string s,str;
	while (getline(infile, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (isChinese(s[i],s[i+1]) == 1)//�Ǻ���������
			{
				i++;
			}
			else
			{
				if (isSign(s[i]) == 1)//�Ƿָ���
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
	unordered_map<string, int> strMap;  //����Ľ��
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
��������:ͳ���ļ�����Ч����
*/
int Cal::CountLine(char *strr)
{
	ifstream infile(strr, ios::in); //�����뷽ʽ���ļ�
	//�ж��Ƿ�򿪳ɹ�
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
�������ܣ�ͳ���ļ��и����ʵĳ��ִ���
*/
int Cal::CountTime(char *strr)
{
	int count = 0, n = 0;
	ifstream infile(strr, ios::in); //�����뷽ʽ���ļ�
	//�ж��Ƿ�򿪳ɹ�
	if (!infile) {
		cout << "open error!" << endl;
		exit(1);
	}
	string s, str;
	while (getline(infile, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (isChinese(s[i], s[i + 1]) == 1)//�Ǻ���������
			{
				i++;
			}
			else
			{
				if (isSign(s[i]) == 1)//�Ƿָ���
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
	map<string, int> strMap;  //����Ľ��
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