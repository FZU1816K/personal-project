#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <String>
#include <fstream>
#include <assert.h>
#include "CountWord.h"
#include "CountChar.h"
#include "CountLine.h"
#include "ShowResult.h"
#include "GetFirstTenWords.h"

using namespace std;

bool g_has_got_map;
bool g_has_got_lines;
bool g_has_got_characters;
int g_characters;
int g_lines;
map<string, int> g_word_count_map;

int main(int argc, char **argv)
{
	string file_location;
	if (argc == 1)
		file_location = "input.txt";
	else if (argc == 2)
		file_location = argv[1];
	else
	{
		cout << "[-]Error: Argument Error!" << endl;
		exit(1);
	}

	g_lines = 0;
	g_characters = 0;
	g_has_got_map = false;
	g_has_got_lines = false;
	g_has_got_characters = false;
	g_word_count_map.clear();


	// 获取词频统计词典 获取词典的过程中顺路统计char、lines的个数
	// 获取完成后直接修改g_has_got_map、g_has_got_lines、g_has_got_char标志位
	GetWordCountMap(file_location);

	int characters = CountChar(file_location);
	int words = CountWord(file_location);
	int lines = CountLine(file_location);
	vector<map<string, int>::iterator> first_ten_words = GetFirstTenWords(file_location);

	ShowResult(characters, words, lines, first_ten_words);
}