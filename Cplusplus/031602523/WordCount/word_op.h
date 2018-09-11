#pragma once
#include "pre.h"
#include "file.h"



struct node {
	string name;//名
	int times;//出现频次
	node *next;
	node(string n, int number)
	{
		name = n;
		times = number;
		next = NULL;
	}
};

class Word_operater
{
private:
	node *hash_table[18280];//哈希表
	int words_cnt;
public:
	string word_str[10];
	int word_times[10];
	Word_operater()
	{
		words_cnt = 0;
		for (int i = 0; i <= 18279; i++)//初始化整个结构体指针数组
		{
			hash_table[i] = new node("", 0);
		}
		for (int j = 0; j < 10; j++)
		{
			word_str[j] = "";
			word_times[j] = 0;
		}
	}
	int get_wrdcnt()
	{
		return this->words_cnt;
	}
	string* get_word_str()
	{
		return this->word_str;
	}
	int* get_w_times()
	{
		return this->word_times;
	}
	void set_wrdcnt(int n)
	{
		this->words_cnt = n; return;
	}
	void insert(string w);
	int words_counter(ifstream &f, Files &fn);
	void file_rank(Files &fn, Word_operater &wn);
};