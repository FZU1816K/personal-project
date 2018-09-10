#include "CountWords.h"

int CutWord(string words)
{
	string temp;
	int count = 0;
	int tempi = 0;
	if (words.size() < 4)	return 0;
	for (int i = 0; i < (int)words.size(); i++)
	{
		if ( ('a' <= words[i] && words[i] <= 'z') || ('A' <= words[i] && words[i] <= 'Z') || ('0' <= words[i] && words[i] <= '9')) {
			temp.resize(words.size());
			temp[++tempi] = words[i];
			if (i == words.size() - 1) {
				if (tempi >= 4) {
					count++;
				}
			}
		}
		else {
			if (tempi>=4) {
				count++;
			}
			if (i + 4 >= (int)words.size()) {
				return count;
			}
			tempi = 0;
		}
	}
	return count;
}
int CountWords(char* file)
{
	int count = 0;
	ifstream inFile;
	string words;
	inFile.open(file, ios::in);
	while (!inFile.eof()) {
		inFile >> words;
		count+=CutWord(words);
		//cout << words<<" "<<count << endl;
	}
	inFile.close();
	return count;
}