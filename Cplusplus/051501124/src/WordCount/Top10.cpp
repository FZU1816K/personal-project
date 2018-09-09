#include "pch.h"
#include "Top10.h"

using namespace std;

unordered_map<string, int> WordFrequency;

struct cmp {
	template<typename T,typename U>
	bool operator()(T const &left, U const &right) {
		if (left.second > right.second) return true;
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


void CountWords(char *filename)
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
				// 9/9mornring
				not_a_word = false;
				if (word.length() >= 4)
				{
					//cnt++;
					//cout << word << endl;
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
					//cnt++;
					WordClassify(word);
				}
			}

		}
		
	}

	WordFrequency.erase(" ");
	
}


bool mysort(const pair<string, int> &left, const pair<string, int> &right)
{
	if (left.second != right.second)
	{
		return left.second > right.second;
	}
	else
	{
		return left.first < right.first;
	}
}

vector<pair<string, int>> top10words(char *filename)
{
	CountWords(filename);
	unordered_map<string, int>::iterator it;
	for (it = WordFrequency.begin(); it != WordFrequency.end(); it++)
	{
		pair<string, int> word = make_pair(it->first, it->second);
		
		if (top10Word.size() == 10)
		{
			pair<string, int> rareWord = top10Word.top();
			if (word.second > rareWord.second ||(word.first < rareWord.first||word.second==rareWord.second))
			{
				top10Word.push(word);
				top10Word.pop();
			}
			else
			{
				top10Word.push(word);
			}
		}
		else
		{
			top10Word.push(word);
		}
	}
	vector<pair<string, int>> result;
	int pq_size = top10Word.size();
	for(int j = 0;j<=pq_size;j++)
	{
		if (top10Word.size() != 0)
		{
			result.push_back(top10Word.top());
			top10Word.pop();
		}

	}
	
	//9/9morning
	if (top10Word.size() != 0)
	{
		result.push_back(top10Word.top());
	}
	

	sort(result.begin(), result.end(), mysort);
	
	/*vector<pair<string, int>>::iterator vit;
	
	for (vit = result.begin(); vit != result.end(); vit++)
	{
		cout << vit->first << ": " << vit->second << endl;
	}*/
	return result;
} 

