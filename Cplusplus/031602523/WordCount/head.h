#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <regex>
#include <algorithm>
#define MAXLENGTH   101

using namespace std;

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

class Files
{
private:
	char file_name[MAXLENGTH];
	int chars_cnt;
	int words_cnt;
	int lines_cnt;
	string allwords;
public:
	Files()
	{
		file_name[0] = '\0';
		allwords = "";
		chars_cnt = 0;
		words_cnt = 0;
		lines_cnt = 1;
	}
	int get_chrcnt()
	{
		return this->chars_cnt;
	}
	void set_chrcnt(int n)
	{
		this->chars_cnt = n; return;
	}
	int get_wrdcnt()
	{
		return this->words_cnt;
	}
	void set_wrdcnt(int n)
	{
		this->words_cnt = n; return;
	}
	int get_lnecnt()
	{
		return this->lines_cnt;
	}
	void set_lnecnt(int n)
	{
		this->lines_cnt = n; return;
	}
	string get_alstring()
	{
		return this->allwords;
	}
	void set_alstring(string s)
	{
		this->allwords = s;
	}
	string get_filename()
	{
		return this->file_name;
	}
	void set_filename(char * s)
	{
		strcpy(this->file_name, s); return;
	}
};

class Char_counter
{
public:
	int char_count(istream &f, Files &fn);

};

class Line_counter
{
public:
	int lines_counter(istream &f, Files &fn);
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
