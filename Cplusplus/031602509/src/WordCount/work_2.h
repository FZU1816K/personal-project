#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;
#define MAX_LENGTH   100
#define HASH_LENGTH	   5639

struct File
{
	char file_path[MAX_LENGTH];		//输入文件路径
	char file_name[MAX_LENGTH];		//文件名
	int count_chars;				//总字符数
	int count_words;				//总单词数
	int count_lines;				//总行数
	File()			
	{								//构造函数初始化
		file_path[0] = '\0';
		file_name[0] = '\0';
		count_chars = 0;
		count_words = 0;
		count_lines = 0;
	}
};

struct Words
{
	string all_string;				//文件内容
	int count_rank[11];				//词频排名
	string word_rank[11];			//词频对应词
	Words()
	{								//构造函数初始化
		all_string = "";
		for (int i = 0; i < 11; i++)
		{
			count_rank[i] = 0;
			word_rank[i] = "";
		}
	}
};
struct Wordnode
{
	string word;					//哈希节点构造
	int count;
	struct Wordnode *next;
};

int C_chars(istream &fl, File &fn, Words &wn);		//统计字符数
int C_words(istream &fl, Words &wn, Wordnode **l);	//统计单词数
int hash_index(string word_str);					//哈希值计算
void hash_insert(Wordnode **l, string word_str);	//开散列插入哈希节点
void rank_word(Wordnode **l, Words &nw);			//词频排名