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
bool CharAlphaJudge(char ch)
{
	if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
		return true;
	return false;
}

// check if char appears in Alpha table or Number table
bool CharAlphaNumberJudge(char ch)
{
	if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
		return true;
	return false;
}

// check the legality of one word
bool WordCheck(string word)
{
	if (word.size() < 4)
		return false;

	for (int i = 0; i < 4; i++)
		if (!CharAlphaJudge(word[i])) return false;
	return true;
}

// check if the line has visible char
bool HaveVisibleChar(string line)
{
	int length = line.size();
	for (int i = 0; i < length; i++)
	{
		if (line[i] != ' ') return true;
	}
	return false;
}


map<string, int> GetWordCountMap(char* file_location)
{
	ifstream instream;
	instream.open(file_location, ios::in);
	assert(instream.is_open());

	string line;
	map<string, int> word_count_map;

	word_count_map.clear();

	while (getline(instream, line))
	{
		int word_left_pos = 0;
		int word_right_pos = 0;
		int word_length = 0;
		int line_length = line.size();

		// statistics words
		while (word_left_pos < line_length)
		{
			while (!CharAlphaJudge(line[word_left_pos]) && word_left_pos < line_length)
				word_left_pos++;
			word_right_pos = word_left_pos;
			while ((word_right_pos < line_length) && (CharAlphaNumberJudge(line[word_right_pos + 1])))
				word_right_pos++;

			word_length = word_right_pos - word_left_pos + 1;
			if (word_length >= 4)
			{
				string word = line.substr(word_left_pos, word_length);
				// transoform the word into lowercase
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				if (WordCheck(word))
				{
					if (word_count_map.count(word) == 0)
						word_count_map[word] = 1;
					else word_count_map[word] += 1;
				}
			}
			word_left_pos = word_right_pos + 1;
		}
	}

	instream.close();

	return word_count_map;
}