#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<string, int> PAIR;
class Frequence
{
public:
	unordered_map<string, int> count_Frequency(string strTmp, unordered_map<string, int> strMap);
	void output_Frequency(string fname, unordered_map<string, int> strMap);
};