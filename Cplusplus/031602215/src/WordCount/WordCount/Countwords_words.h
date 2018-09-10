#pragma once
#include"Countwords.h"
#include<iostream>
#include <cstdlib>    
#include <vector>    
#include <algorithm> 

int cmp(const pair<string, int>& x, const pair<string, int>& y)
{
	return x.second > y.second;
}

void sortMapByValue(map<string, int>& tMap, vector<pair<string, int> >& tVector)
{
	for (map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)
		tVector.push_back(make_pair(curr->first, curr->second));

	sort(tVector.begin(), tVector.end(), cmp);
}

vector<pair<string, int>>  Countwords_words(map<string, int> strMap)
{
	map<string, int>::iterator iter;
	int numwords = 0;
	vector<pair<string, int>> tVector;
	sortMapByValue(strMap, tVector);
	return tVector;
		
	//for (iter = strMap.begin(); iter != strMap.end(); iter++)

	//{
	//	cout << iter->first << " " << iter->second << endl;
//	}
	
}