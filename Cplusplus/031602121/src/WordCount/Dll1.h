#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cassert>
#include <algorithm>
using namespace std;
 __declspec(dllexport) int  CountLines(char *filename);
 __declspec(dllexport) int CountChars(char *filename);
 __declspec(dllexport) bool cmp(int a, int b);
 __declspec(dllexport) void adjustDown(vector<unordered_map<string, int>::iterator> &top, int i);
 __declspec(dllexport) void topK(unordered_map<string, int> &essay, vector<unordered_map<string, int>::iterator> &top);
 __declspec(dllexport) void CountWF(char *filename,ofstream &fout);
 __declspec(dllexport) int CountWords(char *filename);