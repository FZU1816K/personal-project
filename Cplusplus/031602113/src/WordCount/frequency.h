#pragma once
#include<fstream>  //ifstream
#include<iostream>
#include<string>     //°üº¬getline()
#include<algorithm>
#include <vector>
#include<map>
using namespace std;

int cmp(const pair<string, int>& x, const pair<string, int>& y);

class Frequency
{
private:
	string Filename;
	map<string, int> all_words;
	struct  word_map  *Word_list;

public:
	void get_filename(string s);
	void word_map();
	void put_map();
};

