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
#include "CountWord.h"
#include "CountChar.h"
#include "CountLine.h"
#include "ShowResult.h"
#include "GetFirstTenWords.h"



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

		while (word_left_pos < line_length)
		{
			while (!CharAlphaNumberJudge(line[word_left_pos]) && word_left_pos < line_length)
				word_left_pos++;
			if (CharAlphaJudge(line[word_left_pos]))
			{
				word_right_pos = word_left_pos;
				while (((word_right_pos + 1) < line_length) && (CharAlphaNumberJudge(line[word_right_pos + 1])))
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
			else
			{
				word_right_pos = word_left_pos;
				while (((word_right_pos + 1) < line_length) && (CharAlphaNumberJudge(line[word_right_pos + 1])))
					word_right_pos++;
				word_left_pos = word_right_pos + 1;
			}
		}
	}

	instream.close();

	return word_count_map;
}

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

int CountLine(char* file_location)
{
	ifstream instream;
	instream.open(file_location, ios::in);
	assert(instream.is_open());

	string line;
	int valid_lines = 0;
	while (getline(instream, line))
	{
		// statistics valid lines
		if (HaveVisibleChar(line)) valid_lines++;
	}

	instream.close();

	return valid_lines;
}

int CountChar(char* file_location)
{
	ifstream instream;

	// load file in binary mode to statistics characters(inclcude '\r' '\n')
	instream.open(file_location, ios::binary);
	assert(instream.is_open());

	char ch;
	int count_char = 0;
	while (instream.get(ch)) count_char += 1;

	instream.close();
	return count_char;
}

int CountWord(char* file_location)
{
	map<string, int> word_count_map = GetWordCountMap(file_location);

	int count_word = word_count_map.size();
	return count_word;
}

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