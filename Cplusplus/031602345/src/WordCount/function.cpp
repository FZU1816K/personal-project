#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <String>
#include <fstream>
#include <assert.h>
#include "share.h"
#include "CountWord.h"
#include "CountChar.h"
#include "CountLine.h"
#include "ShowResult.h"
#include "GetFirstTenWords.h"

extern bool g_has_got_map;
extern bool g_has_got_lines;
extern bool g_has_got_characters;

extern int g_characters;
extern int g_lines;
extern map<string, int> g_word_count_map;

// ����map<string, int>�������ıȽϺ���
bool compare_bigger(map<string, int>::iterator it1, map<string, int>::iterator it2)
{
	if (it1->second == it2->second)
		return (it1->first.compare(it2->first) < 0);
	return it1->second > it2->second;
}

// �ַ��Ƿ�����ĸ
bool CharAlphaJudge(char ch)
{
	if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
		return true;
	return false;
}

// �ַ��Ƿ�����ĸ or ����
bool CharAlphaNumberJudge(char ch)
{
	if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
		return true;
	return false;
}

// ���word�ĺϷ���
bool WordCheck(string word)
{
	if (word.size() < 4)
		return false;

	for (int i = 0; i < 4; i++)
		if (!CharAlphaJudge(word[i])) return false;
	return true;
}

// ���һ���Ƿ��п���ʾ���ַ�
bool HaveVisibleChar(string line)
{
	int length = line.size();
	for (int i = 0; i < length; i++)
	{
		if (line[i] != ' ') return true;
	}
	return false;
}

// �õ���Ƶ�ֵ���ַ���
void GetWordCountMap(string file_location)
{
	// �ڵõ���Ƶ�ֵ�Ĺ����У�����˳·ͳ�Ƴ��ַ�������Ч����
	// �ڵõ��ֵ䡢�ַ�������Ч������
	// ֱ���޸�ȫ�ֱ���g_has_got_map��g_has_got_line��g_has_got_map������־λ
	// ��CountLine��CountChar��CountWord���������оͲ���Ҫ�ټ���
	ifstream instream;
	instream.open(file_location, ios::binary);
	assert(instream.is_open());

	string line;

	// ȫ�ֱ�����ʼ��
	g_lines = 0;
	g_characters = 0;
	g_word_count_map.clear();
	// int cnt = 0;
	while (true)
	{
		// if ((cnt % 100) == 0) printf("��ǰ���ڴ���%d�� map.size=%d\n", cnt, g_word_count_map.size());
		// cnt += 1;
		bool have_next_line = GetLine(instream, line);

		int word_left_pos = 0;
		int word_right_pos = 0;
		int word_length = 0;
		int line_length = line.size();

		while (word_left_pos < line_length)
		{
			while (!CharAlphaNumberJudge(line[word_left_pos]) && word_left_pos < line_length)
				word_left_pos++;
			word_right_pos = word_left_pos;
			while (((word_right_pos + 1) < line_length) && (CharAlphaNumberJudge(line[word_right_pos + 1])))
				word_right_pos++;
			word_length = word_right_pos - word_left_pos + 1;
			if (word_length >= 4)
			{
				string word = line.substr(word_left_pos, word_length);
				// wordתСд
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				if (WordCheck(word))
				{
					if (g_word_count_map.count(word) == 0)
						g_word_count_map[word] = 1;
					else g_word_count_map[word] += 1;
				}
			}
			word_left_pos = word_right_pos + 1;
		}
		if (!have_next_line) break;
	}

	// ����ֵ���޸ı��λ
	g_has_got_map = true;
	g_has_got_lines = true;
	g_has_got_characters = true;

	// �ر��ļ�
	instream.close();
}

// return a orderd vector of WordNode
vector<map<string, int>::iterator> GetFirstTenWords(string file_location)
{
	if (g_has_got_map == false)
		GetWordCountMap(file_location);

	vector<map<string, int>::iterator> word_node_vectors;
	vector<map<string, int>::iterator> first_ten_words;

	map<string, int>::iterator it = g_word_count_map.begin();

	// int cnt = 0;
	for (; it != g_word_count_map.end(); it++)
	{
		word_node_vectors.push_back(it);
		// if (cnt % 1000 == 0) printf("�Ѿ�Ǩ��%d���ڵ�\n", cnt);
		// cnt += 1;
	}

	int length = word_node_vectors.size();
	int num_show_node = min(10, length);

	// ʹ��sort�Ļ� ��������O(N*Log(N))�ĸ��Ӷ� ֱ��ѡ�ĸ��Ӷ�O(N*10)
	for (int step = 0; step < num_show_node; step++)
	{
		int max_node_id = step;
		map<string, int>::iterator max_node = word_node_vectors[step];
		for (int i = step + 1; i < length; i++)
		{
			if (compare_bigger(word_node_vectors[i], max_node))
			{
				max_node = word_node_vectors[i];
				max_node_id = i;
			}
		}
		swap(word_node_vectors[step], word_node_vectors[max_node_id]);
	}

	// �޸���һ��BUG,Ӧ��ֻ����ǰʮ���ʣ��ɰ汾������ȥ����������һ��
	for (int i = 0; i < num_show_node; i++)
		first_ten_words.push_back(word_node_vectors[i]);

	return first_ten_words;
}

int CountLine(string file_location)
{
	// ����Ѿ��õ� ֱ�ӷ���
	if (g_has_got_lines)
		return g_lines;

	// ֱ��ʹ���ı���ʽ���ļ�
	ifstream instream;
	instream.open(file_location, ios::in);
	assert(instream.is_open());

	string line;
	int valid_lines = 0;
	while (getline(instream, line))
	{
		if (HaveVisibleChar(line)) valid_lines++;
	}

	instream.close();

	return valid_lines;
}

int CountChar(string file_location)
{
	// ����Ѿ��õ� ��ֱ�ӷ���
	if (g_has_got_characters)
		return g_characters;

	ifstream instream;

	// ͨ����������ʽ�����ļ�
	instream.open(file_location, ios::binary);
	assert(instream.is_open());

	char ch;
	int count_char = 0;
	while (instream.get(ch)) count_char += 1;

	instream.close();
	return count_char;
}

int CountWord(string file_location)
{
	// ���û�л���ֵ� �ͻ��һ���ֵ�
	if (!g_has_got_map)
		GetWordCountMap(file_location);

	// int count_word = g_word_count_map.size();
	int count_word = 0;
	map<string, int>::iterator it = g_word_count_map.begin();
	for (; it != g_word_count_map.end(); it++)
		count_word += it->second;
	return count_word;
}

void ShowResult(int characters, int words, int lines, vector<map<string, int>::iterator> first_ten_words)
{
	ofstream outstream;
	outstream.open("result.txt");
	outstream << "characters: " << characters << endl;
	outstream << "words: " << words << endl;
	outstream << "lines: " << lines << endl;

	int length = first_ten_words.size();
	for (int i = 0; i < length; i++)
	{
		outstream << '<' << first_ten_words[i]->first << '>' << ": " << first_ten_words[i]->second << endl;
	}

	outstream.close();
}

// �Զ���getline���� ���غ�������û���ַ�
bool GetLine(ifstream &instream, string &line)
{
	char ch;
	bool have_visible_char = false;
	line.clear();
	while (instream.get(ch))
	{
		g_characters++;
		if (ch == '\n')
		{
			if (have_visible_char) g_lines++;
			return true;
		}
		else if (ch == '\r')
		{
			continue;
		}
		else
		{
			if (ch != ' ') have_visible_char = true;
			line += ch;
		}
	}
	if (have_visible_char) g_lines++;
	return false;
}