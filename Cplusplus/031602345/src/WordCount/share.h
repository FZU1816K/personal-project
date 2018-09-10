#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <String>
#include <fstream>
#include <assert.h>

using namespace std;

struct WordNode
{
	string word;
	int count;

	WordNode()
	{
		word = "";
		count = 0;
	}
	WordNode(string _word, int _count) :word(_word), count(_count) {}

	// overload < for using map and using sort
	bool operator<(WordNode node_comp)
	{
		if (count == node_comp.count)
			return (word < node_comp.word);
		return count > node_comp.count;
	}

	// overload == for using map
	bool operator==(WordNode node_comp)
	{
		if ((word.compare(node_comp.word) == 0 && count == node_comp.count))
			return true;
		return false;
	}
};

// 字符是否是字母
bool CharAlphaJudge(char ch);

// 字符是否是字母 or 数字
bool CharAlphaNumberJudge(char ch);

// 检查word的合法性
bool WordCheck(string word);

// 检查一行是否有可显示的字符
bool HaveVisibleChar(string line);

// 得到词频字典 并在这个过程中统计字符个数
void GetWordCountMap(string file_location);

// 自定义getline函数
bool GetLine(ifstream &instream, string &line);