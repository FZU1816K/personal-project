#include "pch.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include"top_ten.h"
#include"word_count.h"
using namespace std;

int Word_Count(char *filename)						//
{
	string word="";
	char ch;
	int word_cnt = 0;
	fstream f_tmp;
	f_tmp.open(filename);
	if (!f_tmp)
	{
		printf("Can't open file :s% \n Usage:countch filename",filename);
		exit(0);
	}
	while (f_tmp.get(ch))
	{
		if (!Is_Engch(ch) && !Is_Num(ch))
		{
			word = Is_Word(word);
			if (word.length() >= 4)
			{
				word_cnt++;
				word = "";
				continue;
			}
			continue;
		}
		else
		{
			if ((Is_Num(ch) && word.length() > 0)|| Is_Engch(ch))
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
//	printf("words:%d\n", word_cnt);
	return word_cnt;
}