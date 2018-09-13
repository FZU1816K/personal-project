#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
class Word
{
public:
	unordered_map<string, int> count_Word(string fname, unordered_map<string, int> strMap);
};