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
public:
	Word_operater()
	{
		for (int i = 0; i <= 18279; i++)//初始化整个结构体指针数组
		{
			hash_table[i] = new node("", 0);
		}
	}
	void insert(string w);
	int words_counter(ifstream &f, Files &fn);
	void file_rank(Files &fn);
};