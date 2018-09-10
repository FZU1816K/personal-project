#include "pch.h"
#include "CountWords.h"

using namespace std;

int CountAllWords(char *filename)
{
	fstream f(filename);
	string temp;
	int cnt = 0;
	while (f >> temp)
	{
		
		string word = "";
		int i;
		int slen = temp.length();
		bool is_head = true;//at the beginning of a word
		bool not_a_word = false;
		for (i = 0; i < slen; i++)  //todo:avoid digit-first-word
		{
			if ((temp[i] <= '9') && (temp[i]) >= '0') // deal with digit
			{
				if (is_head)
				{
					not_a_word = true;
					continue;
				}
				else
				{
					word += temp[i];
				}
			}
			if ((temp[i] >= 'a') && (temp[i] <= 'z') || (temp[i] >= 'A') && (temp[i] <= 'Z'))
			{
				if (!not_a_word)
				{
					is_head = false;
					word += tolower(temp[i]);
				}
			}

			if (ispunct(temp[i]))//deal with punctions (i.e ',')
			{
				// 9/9mornring
				not_a_word = false;
				if (word.length() >= 4)
				{
					cnt++;
				}
				word = "";
				continue;
			}
			if (i == slen - 1)
			{
				if (word.length() >= 4)
				{
					cnt++;
				}
			}
		}
	}
	return cnt;
}