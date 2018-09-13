#include "pch.h"
#include "CountFrequence.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
typedef pair<string, int> PAIR;
static bool cmp_my_value(const PAIR& lhs, const PAIR& rhs)
{
	if (lhs.second != rhs.second)
	{
		return lhs.second > rhs.second;
	}
	else
	{
		return lhs.first < rhs.first;
	}
}
unordered_map<string, int> Frequence::count_Frequency(string strTmp, unordered_map<string, int> strMap)
{
	unordered_map<string, int>::iterator it = strMap.find(strTmp);
	if (it == strMap.end()) //strMap����������ڵ�ǰ���������һ���¼�ֵ�ԣ�����Ƶ��Ϊ1
	{
		strMap.insert(unordered_map<string, int>::value_type(strTmp, 1));
	}
	else                   //������������Ƶ��+1
		strMap[strTmp]++;
	return strMap;
}
void Frequence::output_Frequency(string fname, unordered_map<string, int> strMap)
{
	ofstream file(fname, ios::app);
	vector<PAIR> strVec(strMap.begin(), strMap.end());
	if (strVec.size() == 0)
	{
		file.close();
		return;
	}
	sort(strVec.begin(), strVec.end(), cmp_my_value);
	for (int i = 0; i < strVec.size(); i++)
	{
		if (i == 10)break;
		file << strVec[i].first.c_str() << ':' << strVec[i].second << endl;			//һ������ʹ������ð�ţ�������������
	}
	file.close();
}