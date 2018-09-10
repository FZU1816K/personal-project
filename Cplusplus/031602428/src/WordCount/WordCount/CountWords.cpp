#include "CountWords.h"

int CutWord(string words)
{
	string temp;
	temp.resize(words.size());
	int count = 0;
	int tempi = 0;
	if (words.size() < 4)	return 0;
	for (int i = 0; i < (int)words.size(); i++)
	{
		if (tempi < 4 && ( ('a' <= words[i] && words[i] <= 'z') || ('A' <= words[i] && words[i] <= 'Z') ) ) {
			temp[tempi++] = words[i];
			if (i == words.size() - 1)	count++;
		}
		else if (tempi >= 4) {
			if (('a' <= words[i] && words[i] <= 'z') || ('A' <= words[i] && words[i] <= 'Z') || ('0' <= words[i] && words[i] <= '9')) {
				temp[tempi++] = words[i];
				if (i == words.size() - 1)	count++;
			}
			else {
				count++;
				if (i + 4 >= (int)words.size()) {
					//cout << words << "1:" << count << endl;
					return count;
				}
				tempi = 0;
			}
		}
		else {
			if (i + 4 >= (int)words.size()) {
				//cout << words << "3:" << count << endl;
				return count;
			}
			tempi = 0;
		}
	}
	//cout << words << "2:" << count << endl;
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
		//cout << words<<" count:"<<count << endl;
	}
	inFile.close();
	return count;
}