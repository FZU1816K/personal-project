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

int CountWord(char* file_location)
{
	map<string,int> word_count_map = GetWordCountMap(file_location);
	
	int count_word = word_count_map.size();
	return count_word;
}