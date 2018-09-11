#include<iostream>
#include<string>
#include<map>
#include <fstream>
#include <algorithm>
#include<vector>
#include <assert.h>
using namespace std;

int character(char* path);
int word(char* path);
int isstring(string c);
string mytolower(string s);
void WordsFrequency(char* path);
int cmp(const pair<string, int>& x, const pair<string, int>& y);
vector<string> splitt(const string &s);
int main(int args, char* argv[]);