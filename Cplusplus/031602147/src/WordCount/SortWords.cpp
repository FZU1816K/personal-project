/**
* Function:  SortWords
* Description:  Sort the words
* Parameter:
  top:he highest frequency word array
  MapWord:the words map
  words:the number of words
*/
#include"SortWords.h"

void SortWords(pair<string, int> top[],map<string, int> &MapWord,int words)
{
	for (int i = 0; i < 10&&i<words; i++)
	{
		pair<string, int> max;
		max.first = "";
		max.second = 0;
		map<string, int>::iterator iter;
		for (iter = MapWord.begin(); iter != MapWord.end(); ++iter)
		{
			if (max.second <= iter->second)
			{
				max.first = iter->first;
				max.second = iter->second;
			}
		}
		top[i] = max;
		/*Find the highest frequency word and add an array.*/
		map<string, int>::iterator x;
		x = MapWord.find(max.first);
		MapWord.erase(x);
		/*Culling the word with the highest frequency.*/
	}
	return ;
}
