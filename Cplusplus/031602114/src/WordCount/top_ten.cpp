#include "pch.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<map>
#include<fstream>
#include<algorithm>
#include"top_ten.h"
using namespace std;

ostream  &operator<<(ostream &os, const Top_Ten &top_ten)
{
	os << "<" << top_ten.word << ">: " << top_ten.number;
	return os;
}
bool Cmp(const Top_Ten& top1, const Top_Ten& top2)
{
	if (top1.number != top2.number)
	{
		return top1.number > top2.number;
	}
	else
	{
		return top1.word < top2.word;
	}
}

string Is_Word(string word)
{
	int lenth = word.length();
	string true_word;
	string fal_word = "";
	if (lenth < 4 || (lenth >= 4 && (!Is_Engch(word[0]) || !Is_Engch(word[1]) || !Is_Engch(word[2]) || !Is_Engch(word[3]))))
	{
		return fal_word;
	}
	else
	{
		while (!Is_Engch(word[lenth - 1]) && !Is_Num(word[lenth - 1]))			//可能存在省略号的情况,比如This is aaaa test file...
		{
			lenth--;
		}
		for (int j = 0; j < lenth; j++)
		{
			true_word += tolower(word[j]);
		}
		return true_word;
	}
}

bool Is_Engch(char ch)					//字符是a~z或A~Z之间的英文字母
{
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Is_Num(char ch)					//字符是0~9之间的数字
{
	if (ch >= '1'&& ch <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int In_Top(Top_Ten words[],string word)
{
	for (int i = 0; i < 10; i++)
	{
		if (words[i].word == word)
		{
			return i;
		}
	}
	return -1;
}

void Top_Tenwords(Top_Ten words[],char *filename)
{
	fstream f_tmp;
	string word = "";
	char ch;
	map<string, int > all_words;
	int i = 0;
	f_tmp.open(filename);
	if (!f_tmp)
	{
		printf("Can't open file :s% \n Usage:countch filename", filename);
		exit(0);
	}
	while (1)
	{
		if (!f_tmp.get(ch))
		{
			word = Is_Word(word);
			if (word.length() >= 4)
			{
				all_words[word]++;
				int loca_tmp = In_Top(words, word);
				if (all_words.size() < 10 && loca_tmp == -1)
				{
					int tmp = all_words[word];
					words[i].number = tmp;
					words[i].word = word;
					i++;
				}
				else if (all_words.size() < 10 && loca_tmp != -1)
				{
					words[loca_tmp].number = all_words[word];
				}
				else if (all_words.size() == 10 && loca_tmp == -1)
				{
					int tmp = all_words[word];
					words[i].number = tmp;
					words[i].word = word;
					sort(words, words + 10, Cmp);
				}
				else if (all_words.size() == 10 && loca_tmp != -1)
				{
					words[loca_tmp].number = all_words[word];
					sort(words, words + 10, Cmp);
				}
				else if (all_words.size() > 10)
				{
					if (all_words[word] > words[9].number && loca_tmp == -1)
					{
						words[9].word = word;
						words[9].number = all_words[word];
						sort(words, words + 10, Cmp);
					}
					else if (all_words[word] > words[9].number && loca_tmp != -1)
					{
						words[loca_tmp].number = all_words[word];
						sort(words, words + 10, Cmp);
					}
					else if (all_words[word] == words[9].number)
					{
						if (word < words[9].word)
						{
							words[9].word = word;
							words[9].number = all_words[word];
							sort(words, words + 10, Cmp);
						}
					}
				}
			}
			break;
		}
		if (!Is_Engch(ch) && !Is_Num(ch))
		{
			word = Is_Word(word);
			if (word.length() >= 4)
			{
				all_words[word]++;
				int loca_tmp = In_Top(words, word);
				if (all_words.size() < 10 && loca_tmp == -1)
				{
					int tmp = all_words[word];
					words[i].number = tmp;
					words[i].word = word;
					i++;
				}
				else if (all_words.size() < 10 && loca_tmp != -1)
				{
					words[loca_tmp].number = all_words[word];
				}
				else if (all_words.size() == 10 && loca_tmp == -1)
				{
					int tmp = all_words[word];
					words[i].number = tmp;
					words[i].word = word;
					sort(words, words + 10, Cmp);
				}
				else if (all_words.size() == 10 && loca_tmp != -1)
				{
					words[loca_tmp].number = all_words[word];
					sort(words, words + 10, Cmp);
				}
				else if(all_words.size() > 10 )
				{
					if (all_words[word] > words[9].number && loca_tmp == -1)
					{
						words[9].word = word;
						words[9].number = all_words[word];
						sort(words, words + 10, Cmp);
					}
					else if (all_words[word] > words[9].number && loca_tmp != -1)
					{
						words[loca_tmp].number = all_words[word];
						sort(words, words + 10, Cmp);
					}
					else if (all_words[word] == words[9].number)
					{
						if (word < words[9].word)
						{
							words[9].word = word;
							words[9].number = all_words[word];
							sort(words, words + 10, Cmp);
						}
					}
				}
			}
			word = "";
			continue;
		}
		else
		{
			if ((Is_Num(ch) && word.length() > 0) || Is_Engch(ch))
			{
				word += ch;
				continue;
			}
			else if (Is_Num(ch) && word.length() == 0)
			{
				continue;
			}
		}
	}
	f_tmp.close();
}