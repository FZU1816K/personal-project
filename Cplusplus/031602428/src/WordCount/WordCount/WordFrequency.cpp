#include "WordFrequency.h"

string word[1010];
int cnt = 0;
struct wordFrequency {
	string word;
	int frequency = 0;
}wordFre[1010];
string SwitchToLower(string words)
{
	int len = words.length();
	for (int i = 0; i < len; i++)
	{
		if ('A' <= words[i] && words[i] <= 'Z')
			words[i] += 32;
	}
	return words;
}
void CutWord(string words)
{
	string temp;
	temp.resize(words.size());
	int count = 0;
	int tempi = 0;
	if (words.size() < 4)	return ;
	for (int i = 0; i < (int)words.size(); i++)
	{
		if (tempi < 4 && (('a' <= words[i] && words[i] <= 'z') || ('A' <= words[i] && words[i] <= 'Z'))) {
			temp[tempi++] = words[i];
			if (i == words.size() - 1) {
				temp.resize(tempi);
				word[++cnt] = SwitchToLower(temp);
			}
		}
		else if (tempi >= 4) {
			if (('a' <= words[i] && words[i] <= 'z') || ('A' <= words[i] && words[i] <= 'Z') || ('0' <= words[i] && words[i] <= '9')) {
				temp[tempi++] = words[i];
				if (i == words.size() - 1) {
					temp.resize(tempi);
					word[++cnt] = SwitchToLower(temp);
				}
			}
			else {
				temp.resize(tempi);
				word[++cnt] = SwitchToLower(temp);
				if (i + 4 >= (int)words.size()) {
					//cout << words << "1:" << count << endl;
					return ;
				}
				tempi = 0;
			}
		}
		else {
			if (i + 4 >= (int)words.size()) {
				//cout << words << "3:" << count << endl;
				return ;
			}
			tempi = 0;
		}
	}
	//cout << words << "2:" << count << endl;
	return ;
}
bool cmp(string a, string b)
{
	return a.compare(b) < 0;
}
bool cmp2(wordFrequency& a, wordFrequency& b) {
	return a.frequency > b.frequency;
}
void WordFrequency(char* file)
{
	int count2 = 0;
	string words;
	ifstream inFile;
	inFile.open(file, ios::in);
	while (!inFile.eof()) {
		inFile >> words;
		CutWord(words);
	}
	inFile.close();
	sort(word + 1, word + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
	{
		if (i == 1) {
			wordFre[++count2].word = word[i];
			wordFre[count2].frequency++;
		}
		else if (word[i - 1] == word[i]) {
			wordFre[count2].frequency++;
		}
		else {
			wordFre[++count2].word = word[i];
			wordFre[count2].frequency++;
		}
	}
	/*for (int i = 1; i <= count2; i++)
	{
		cout << wordFre[i].word << ":" << wordFre[i].frequency << endl;
	}*/
	sort(wordFre + 1, wordFre + count2 + 1, cmp2);
	for (int i = 1; i <= min(count2, 10); i++)
	{
		cout << wordFre[i].word << ":" << wordFre[i].frequency <<endl;
	}
	return;
}