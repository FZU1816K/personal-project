#include"Sort.h"

//ʹ������vector��ʮ�ַ����sort�����н������С�


int Compare(const pair <string, int> & x, const pair<string, int>& y)
{
	return x.second > y.second;
}

void Sort(unordered_map<string, int>& tMap, vector<pair<string, int> >& tVector)
{
	for (unordered_map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)
		tVector.push_back(make_pair(curr->first, curr->second));

	sort(tVector.begin(), tVector.end(), Compare);
}