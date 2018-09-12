#include<iostream>
#include<fstream>
#include"WordCount.h"

vector<pair<string, int>> VM;
void topTen()
{
	
	for (auto it = My.begin(); it != My.end(); it++)
	{
		VM.push_back(make_pair(it->first, it->second));
	}
	sort(VM.begin(), VM.end(), [](const pair<string, int> &x, const pair<string, int>&y)->int {return x.second > y.second; });
	int c = 0;
}

int main()
{
	file f("C:/Users/Matthew Li/Desktop/input.txt");
	f.countChar_Line(f.Filename);
	f.countWord1();
	ofstream fout("C:/Users/Matthew Li/Desktop/output.txt");
	cout << "characters: " << f.numChar << endl;
	cout << "words: " << f.numWords << endl;
	cout << "lines: " << f.numLine << endl;

	fout << "characters: " << f.numChar << endl;
	fout << "words: " << f.numWords << endl;
	fout << "lines: " << f.numLine << endl;

	topTen();
	int c = 0;
	for (auto it = VM.begin(); c < 10; it++, c++)
	{
		cout << "<" << it->first << ">" << ": " << it->second << endl;
		fout << "<" << it->first << ">" << ": " << it->second << endl;
	}
	fout.close();
	system("pause");
	return 0;
}