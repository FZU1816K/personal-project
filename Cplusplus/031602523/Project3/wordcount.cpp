#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <regex>
#include <algorithm>
#define MAXLENGTH   101


//https://blog.csdn.net/nichengwuxiao/article/details/78789225
//https://www.cnblogs.com/batman425/p/3179520.html
//https://www.cnblogs.com/hexiaobao/p/8134829.html

using namespace std;

struct files
{
	char file_path[MAXLENGTH];
	char file_name[MAXLENGTH];
	int chars_cnt;
	int words_cnt;
	int lines_cnt;
	files()
	{
		file_path[0] = '\0';
		file_name[0] = '\0';
		chars_cnt = 0;
		words_cnt = 0;
		lines_cnt = 1;
	}
};

struct words
{
	string allwords;
	int rank_cnt[11];
	string rank_name[11];
	words()
	{
		allwords = "";
		for (int i = 0; i < 11; i++)
		{
			rank_cnt[i] = 0;
			rank_name[i] = "";
		}
	}
};

int chars_counter(istream &f, files &fn, words &wn)
{
	char temp;
	int cnt = 0;
	while (!f.eof())
	{
		f.get(temp);
		if ((temp <= 126 && temp >= 32) || temp == 9 || temp == 10)
		{
			wn.allwords += temp;
			cnt++;
		}
	}

	return cnt;
}






int main(int argc, char *argv[])
{
	ifstream f;
	files file_input;
	words word;

	strcpy(file_input.file_name, argv[1]);
	cout << file_input.file_name << endl;

	f.open(file_input.file_name, ios::in);
	if (!f.is_open())
	{
		cout << "Warning! can't open this file!" << endl;
	}

	file_input.chars_cnt = chars_counter(f, file_input, word);


	cout << file_input.chars_cnt << endl;

	system("pause");
	return 0;
}
