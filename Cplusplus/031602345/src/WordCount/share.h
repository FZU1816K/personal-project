#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <String>
#include <fstream>
#include <assert.h>

using namespace std;

struct WordNode
{
	string word;
	int count;

	WordNode()
	{
		word = "";
		count = 0;
	}
	WordNode(string _word, int _count) :word(_word), count(_count) {}

	// overload < for using map and using sort
	bool operator<(WordNode node_comp)
	{
		if (count == node_comp.count)
			return (word < node_comp.word);
		return count > node_comp.count;
	}

	// overload == for using map
	bool operator==(WordNode node_comp)
	{
		if ((word.compare(node_comp.word) == 0 && count == node_comp.count))
			return true;
		return false;
	}
};

// check if the char appears in Alpha table
bool CharAlphaJudge(char ch);

// check if char appears in Alpha table or Number table
bool CharAlphaNumberJudge(char ch);

// check the legality of one word
bool WordCheck(string word);

// check if the line has visible char
bool HaveVisibleChar(string line);

// get the word-count map
map<string, int> GetWordCountMap(char* file_location);