#include "pch.h"
#include "CountWords.h"

using namespace std;

unordered_map<string, int> WordFrequency;

struct cmp {
	template<typename T,typename U>
	bool operator()(T const &left, U const &right) {
		if (left.second < right.second) return true;
		return false;
	}

};
priority_queue<pair<string, int>, vector<pair<string, int>>, cmp > top10Word;


void WordClassify(string word)
{
	if (WordFrequency.count(word) == 0)
	{
		WordFrequency[word] = 1;
	}
	else
	{
		WordFrequency[word] += 1;
	}

}


int CountWords(char *filename)
{
	fstream f(filename);
	string temp;
	int cnt = 0;
	while (f>>temp)
	{
		bool is_head = true;//at the beginning of a word
		bool not_a_word = false;
		string word="";
		int i;
		int slen = temp.length();
		for (i = 0;i<slen;i++)  //todo:avoid digit-first-word
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
			if ((temp[i] >= 'a') && (temp[i] <= 'z')||(temp[i] >= 'A') && (temp[i] <= 'Z'))
			{
				if (!not_a_word)
				{
					is_head = false;
					word += tolower(temp[i]);
				}
			}

			if (ispunct(temp[i]))//deal with punctions (i.e ',')
			{
				
				//cout << word << endl;
				if (word.length() >= 4)
				{
					cnt++;
					WordClassify(word);
				}
				word = "";
				continue;
			}
			if (i == slen - 1)
			{
				//cout << word << endl;
				if (word.length() >= 4)
				{
					cnt++;
					WordClassify(word);
				}
			}

		}
		
	}
	return cnt;
}

int getAns()
{
	return WordFrequency["hello"];
}

