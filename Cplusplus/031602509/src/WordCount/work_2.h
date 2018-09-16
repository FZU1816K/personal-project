#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include<vector>
#include <algorithm>
using namespace std;
#define MAX_LENGTH   100
#define HASH_LENGTH	   5639

struct File
{
	char file_path[MAX_LENGTH];		//�����ļ�·��
	char file_name[MAX_LENGTH];		//�ļ���
	int count_chars;				//���ַ���
	int count_words;				//�ܵ�����
	int count_lines;				//������
	File()
	{								//���캯����ʼ��
		file_path[0] = '\0';
		file_name[0] = '\0';
		count_chars = 0;
		count_words = 0;
		count_lines = 0;
	}
};

struct Words
{
	string all_string;				//�ļ�����
	int count_rank[11] = { 0 };				//��Ƶ����
	string word_rank[11] = { "" };			//��Ƶ��Ӧ��
	Words()
	{								//���캯����ʼ��
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
	string word;					//��ϣ�ڵ㹹��
	int count = 1;
	struct Wordnode *next = NULL;
};

int C_chars(istream &fl, File &fn, Words &wn, vector <string> &str_lines);		//ͳ���ַ���
int C_words(istream &fl, File &fn, Words &wn, Wordnode **l, vector <string> &str_lines);	//ͳ�Ƶ�����
int hash_index(string word_str);					//��ϣֵ����
void hash_insert(Wordnode **l, string word_str);	//��ɢ�в����ϣ�ڵ�
void rank_word(Wordnode **l, Words &nw);			//��Ƶ����