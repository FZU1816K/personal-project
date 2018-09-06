#include "WordFrequency.h"

unordered_map<string, int> hash_table;
unordered_map<string, int>::iterator hash_iter;

map<pair<int, string>, string, MyCompare> wordMap;
map<pair<int, string>, string>::iterator map_iter;

int TransitionStoreWord(int state, char input, string & word)
{
	switch (state)
	{
	case OUTWORD:
		if (!isalpha(input) || isspace(input)) return OUTWORD;
		else if (isalpha(input)) { word += input; return P1; }

	case P1:
		if (isalpha(input)) { word += input; return  P2; }
		else { word.clear(); return OUTWORD; }

	case P2:
		if (isalpha(input)) { word += input; return  P3; }
		else { word.clear(); return OUTWORD; }

	case P3:
		if (isalpha(input)) { word += input; return INWORD; }
		else { word.clear(); return OUTWORD; }

	case INWORD:
		if (isalnum(input)) { word += input; return INWORD; }
		else {
			InsertToHashTable(word);
			//cout << word << endl;
			word.clear();
			return OUTWORD;
		}
	}
	return ERROR;
}

void InsertToHashTable(string & word)
{
	if ((hash_iter = hash_table.find(word)) == hash_table.end()) { // a new word
		pair<string, int> newword = pair<string, int>(word, 1);
		hash_table.insert(newword);
		// cout << "insert word " << word << " into hashtable" << endl;
	}
	else { // A word previously appeared
		hash_iter->second++;
		pair<string, int> oldword = pair<string, int>(word, hash_iter->second);
		// cout << "A word exited in table. Number of occurrences:" << hash_iter->second << endl;
	}
}

void WordFrequency(char * filename)
{
	string word;
	char c;
	fstream file;
	file.open(filename, ios::in);
	int state = OUTWORD;
	while (file.get(c) && state != ERROR) {
		state = TransitionStoreWord(state, c, word);
	}
	if (state == INWORD) {
		InsertToHashTable(word);
	}
}

void TopTenWords()
{
	// Traverse the hash table and insert the words inside into the red-black tree for proper sorting output.
	for (hash_iter = hash_table.begin(); hash_iter != hash_table.end(); hash_iter++) {
		wordMap.insert(make_pair(make_pair(hash_iter->second, hash_iter->first), hash_iter->first));
	}
	if (wordMap.size() == 0)
		return;

	if (wordMap.size() == 1) {
		map_iter = wordMap.begin();
		cout << map_iter->first.first << " " << map_iter->first.second << endl;
		return;
	}

	// Use the properties of the binary search tree to output ten most frequently words.
	map_iter = wordMap.end();
	map_iter--;
	int counter = 0;
	for (; map_iter != wordMap.begin() && counter < 10; map_iter--, counter++) {
		cout << map_iter->first.first << " " << map_iter->first.second << endl;
	}
	cout << map_iter->first.first << " " << map_iter->first.second << endl;
	return;
}
