#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

int CountWords(char *file);

vector< pair<string, int> > top10words();