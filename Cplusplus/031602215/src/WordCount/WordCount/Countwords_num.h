#pragma once
#include"Countwords.h"

int Countwords_num(map<string, int> strMap)
{
	map<string, int>::iterator iter;
	int numwords = 0;
	for (iter = strMap.begin(); iter != strMap.end(); iter++)

	{
		numwords += iter->second;
		//	cout << iter->first << " " << iter->second << endl;
	}
	return numwords;
}