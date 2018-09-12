#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using std::string;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using namespace std;



int Compare(const pair <string, int> & x, const pair<string, int>& y);
void Sort(unordered_map<string, int>& newmap, vector<pair<string, int> >& newvector);
