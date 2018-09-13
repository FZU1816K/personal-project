#pragma once
#ifndef _RANKWORD_H_
#define _RANKWORD_H_
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<iterator>
#include<cctype>
#include<unordered_map>
#define Begin 0
#define Wrong 1
#define L2 2
#define L3 3
#define L4 4
#define Final 5
#define ERROR 6
using namespace std;

int store_word(int state, char input, string word);
unordered_map<string, int> scaner(char * filename);
bool Compare(const pair<int, string>& word1, const pair<int, string>& word2);
int Output(vector<pair<int, string>>& Top10words);
vector<pair<int, string>> RankWord(unordered_map<string, int>);
#endif