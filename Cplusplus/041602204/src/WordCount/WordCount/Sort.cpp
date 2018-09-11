#include"Sort.h"

//使用容器vector里十分方便的sort来进行降序排列。


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