#include"pch.h"
#include "rankword.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<iterator>
#include<cctype>
#include<unordered_map>
#include<queue>
#include "countword.h"
using namespace std;
unordered_map<string, int>::iterator hash_inter;
unordered_map<string, int> strMap; 
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>> > wordQueue;

int store_word(int state, char input, string word)
{
	switch (state)
	{
	case Begin:
		if (isspace(input) || (!(input >= '0') && !(input <= '9'))) return Begin;

		if (isalpha(input)) return L2;
		if ((input >= '0'&&input <= '9')) return Wrong;

	case Wrong:

		if (isspace(input) || (!(input >= '0') && !(input <= '9'))) return Begin;
		else return Wrong;

	case L2:
		if ((input >= '0'&&input <= '9')) return Wrong;
		if (isalpha(input)) return L3;
		else return Begin;

	case L3:
		if ((input >= '0'&&input <= '9')) return Wrong;
		if (isalpha(input)) return L4;
		else return Begin;

	case L4:
		if ((input >= '0'&&input <= '9')) return Wrong;
		if (isalpha(input)) return Final;
		else return Begin;

	case Final:
		if (isalnum(input)) return Final;
		else 
		{ 
			if ((hash_inter = strMap.find(word)) == strMap.end())
			{
				pair<string, int> newWord = pair<string, int>(word, 1);
				strMap.insert(newWord);
			}
			else
			{
				hash_inter->second++;
				pair<string, int> oldword = pair<string, int>(word, hash_inter->second);
			}
			word.clear();
			return Begin; 
		}
	}
	return ERROR;
}
bool Compare(const pair<int, string>& word1, const pair<int, string>& word2)
{
	if (word1.first != word2.first)
	{
		return word1.first > word2.first;
	}
	else
	{
		return word1.second < word2.second;
	}
}

unordered_map<string, int> scaner(char * filename)
{
	int count = 0;
	char c;
	string word;
	std::fstream outfile;
	outfile.open(filename, std::ios::in);
	int state = Begin;
	while (outfile.get(c) && state != ERROR) {
		c = tolower(c);
		state = store_word(state, c, word);
	}
	if (state == Final) 
	{
		
		if ((hash_inter = strMap.find(word)) == strMap.end()) 
		{ 
			pair<string, int> newWord = pair<string, int>(word, 1);
			strMap.insert(newWord);
		}
		else 
		{ 
			hash_inter->second++;
			pair<string, int> oldword = pair<string, int>(word, hash_inter->second);
		}
	}
	return strMap;
}

vector<pair<int, string>> RankWord(unordered_map<string, int> strMap)

{
	for (hash_inter = strMap.begin(); hash_inter != strMap.end(); hash_inter++) 
	{
		pair<int, string> currentWord = make_pair(hash_inter->second, hash_inter->first);
		if (wordQueue.size() == 10) {
			pair<int, string> minWord = wordQueue.top();
			if (currentWord.first > minWord.first || (currentWord.first == minWord.first
				&&currentWord.second > minWord.second)) {
				wordQueue.pop();
				wordQueue.push(currentWord);
			}
		}
		else {
			wordQueue.push(currentWord);
		}
	}

	vector<pair<int, string>> Top10words;

	while (!wordQueue.empty()) 
	{
		Top10words.push_back(wordQueue.top());
		wordQueue.pop();
	}

	sort(Top10words.begin(), Top10words.end(), Compare);
	strMap.clear();
	
	return Top10words;
}

int Output(vector<pair<int, string>>& Top10words)
{
	if (Top10words.size() == 0) {
		return -1;
	}

	vector<pair<int, string>>::iterator iter;
	for (iter = Top10words.begin(); iter != Top10words.end(); iter++) {
		const char *word = iter->second.c_str();
		printf("%s: %d\n", word, iter->first);
	}
	return 0;
}