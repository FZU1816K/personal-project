#include<iostream>
#include"WordCount.h"

void topTen()
{
	vector<pair<string, int>> VM;
	for (auto it = My.begin(); it != My.end(); it++)
	{
		VM.push_back(make_pair(it->first, it->second));
	}
	sort(VM.begin(), VM.end(), [](const pair<string, int> &x, const pair<string, int>&y)->int {return x.second > y.second; });
	int c = 0;
	for (auto it = VM.begin(); c < 10; it++, c++)
	{
		cout << it->first << ":" << it->second << endl;
	}
}

int main()
{
	file f("C:/Users/Matthew Li/Desktop/Test1.txt");
	f.countChar_Line(f.Filename);
	f.countWord1();

	cout << "characters:" << f.numChar << endl;
	cout << "words:" << f.numWords << endl;
	cout << "lines:" << f.numLine << endl;

	topTen();

	system("pause");
	return 0;
}