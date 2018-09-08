#include "WordFrequency.h"

unordered_map<string, int> hash_table;
unordered_map<string, int>::iterator hash_iter;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> wordQueue;

bool MySort(const pair<int, string>& word1, const pair<int, string>& word2)
{
	if (word1.first != word2.first) {  // Sort word with frequency, high to low
		return word1.first > word2.first;
	}
	else // if words have the same frequency, output in dictionary order
	{
		return word1.second < word2.second;
	}
}

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
		if (isalpha(input)) { word += input; return VALIDWORD; }
		else { word.clear(); return OUTWORD; }

	case VALIDWORD:
		if (isalnum(input)) { word += input; return VALIDWORD; }
		else {
			InsertToHashTable(word);
			word.clear();
			return OUTWORD;
		}
	}
	return ERROR;
}

void InsertToHashTable(string & word)
{
	if ((hash_iter = hash_table.find(word)) == hash_table.end()) { // a new word
		pair<string, int> newWord = pair<string, int>(word, 1);
		hash_table.insert(newWord);
	}
	else { // A word previously appeared
		hash_iter->second++;
		pair<string, int> oldword = pair<string, int>(word, hash_iter->second);
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
		c = tolower(c);
		state = TransitionStoreWord(state, c, word);
	}
	if (state == VALIDWORD) {
		InsertToHashTable(word);
	}
}

int TopTenWords()
{
	for (hash_iter = hash_table.begin(); hash_iter != hash_table.end(); hash_iter++) {
		pair<int, string> currentWord = make_pair(hash_iter->second, hash_iter->first);
		if (wordQueue.size() == 10) {
			pair<int, string> minFreqWord = wordQueue.top();
			if (currentWord.first > minFreqWord.first || (currentWord.first == minFreqWord.first
				&&currentWord.second > minFreqWord.second)) {
				wordQueue.pop();
				wordQueue.push(currentWord);
			}
		}
		else {
			wordQueue.push(currentWord);
		}
	}
	if (wordQueue.size() == 0) {
		return -1;
	}
	int count = wordQueue.size();
	vector<pair<int, string>> Top10words;
	
	while (!wordQueue.empty()) {
		Top10words.push_back(wordQueue.top());
		wordQueue.pop();
	}
	
	sort(Top10words.begin(), Top10words.end(), MySort);
	vector<pair<int, string>>::iterator iter;
	for (iter = Top10words.begin(); iter != Top10words.end(); iter++) {
		//cout << iter->first << " " << iter->second << endl;
		const char *word = iter->second.c_str();
		printf("%s: %d\n", word, iter->first);
	}
	hash_table.clear();
	return count;
}
