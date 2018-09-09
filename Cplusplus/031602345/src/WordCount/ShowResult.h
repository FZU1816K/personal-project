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

void ShowResult(int characters, int words, int lines, vector<WordNode> first_ten_words)
{
	ofstream outstream;
	outstream.open("result.txt");
	outstream << "characters: " << characters << endl;
	outstream << "words: " << words << endl;
	outstream << "lines: " << lines << endl;

	int num_should_show = min(words, 10);
	for (int i = 0; i < num_should_show; i++)
		outstream << first_ten_words[i].word << ": " << first_ten_words[i].count << endl;

	outstream.close();
}