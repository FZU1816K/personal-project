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
#include "share.h"

using namespace std;

// return a orderd vector of WordNode
vector<WordNode> GetFirstTenWords(char* file_location)
{
	vector<WordNode> word_node_vectors;
	map<string, int> word_count_map = GetWordCountMap(file_location);

	// extract words from g_word_count_map, then save them into g_word_node_vectors
	map<string, int>::iterator it = word_count_map.begin();

	for (int i = 0; it != word_count_map.end(); i++, it++)
		word_node_vectors.push_back(WordNode(it->first, it->second));

	// according to the overload function, sort the g_word_node_vectors
	sort(word_node_vectors.begin(), word_node_vectors.end());

	return word_node_vectors;
}