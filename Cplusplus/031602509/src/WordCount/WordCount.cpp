#define _CRT_SECURE_NO_DEPRECATE
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
	char file_path[MAX_LENGTH];
	char file_name[MAX_LENGTH];
	int count_chars;
	int count_words;
	int count_lines;
	File()
	{
		file_path[0] = '\0';
		file_name[0] = '\0';
		count_chars = 0;
		count_words = 0;
		count_lines = 1;
	}
};
struct Words
{
	string all_string;
	int count_rank[11];
	string word_rank[11];
	Words()
	{
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
	string word;
	int count;
	struct Wordnode *next;
};
int hash_index(string word_str)
{
	int value = 0,i = 0;
	int length = word_str.length();
	for (i = 0; i < length; i++)
	{
		value = (29 * value + word_str[i])%HASH_LENGTH;//哈希散列
		//cout << value << endl;
	}
	return value;
}
void hash_insert(Wordnode **l, string word_str)
{
	int value = hash_index(word_str);
	Wordnode *p;
	//cout << value;
	for (p = l[value]; p != NULL; p = p->next)
	{
		if (word_str == p->word)
		{
			p->count++;
			return;
		}
	}
	p = new Wordnode;
	p->count = 1;
	p->word = word_str;
	p->next = l[value];
	l[value] = p;
}


int C_chars(istream &fl,File &fn,Words &wn)
{
	char chr;
	int count_c = 0;
	while (!fl.eof())
	{
		fl.get(chr);
		if ((chr <= 126 && chr >= 32)||chr==9||chr==10)
		{
			if (fl.eof())
				break;
			wn.all_string += chr;
			count_c++;
			if (chr == 10)
				fn.count_lines++;
			//cout << chr <<" "<<count_c<< endl;
		}
	}
	return count_c;
}
int C_words(istream &fl,Words &wn,Wordnode **l)
{
	int count = 0;
	regex pattern("[a-zA-Z]{4}[a-zA-Z0-9]*");
	smatch result;
	//cout << regex_search(wn.all_string, result, pattern)<<endl;
	string::const_iterator start = wn.all_string.begin();
	string::const_iterator end = wn.all_string.end();
	string temp_str;
	while (regex_search(start,end, result, pattern))
	{
		//cout<<"successfully match";
		temp_str = result[0];
		transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);//转换为小写单词
		hash_insert(l, temp_str);
		//cout << temp_str<<" ";
		count++;
		start = result[0].second;
	}
	cout << endl;
	return count;
}

void rank_word(Wordnode **l,Words &nw)
{
	int i = 0,j = 0,max = 0;
	Wordnode *p, *max_node = NULL;
	for (j = 1; j < 11; j++)
	{
		for (i = 0; i < HASH_LENGTH; i++)
		{
			for (p = l[i]; p != NULL; p = p->next)
			{
				if (p->count > max)
				{
					max = p->count;
					max_node = p;
					nw.count_rank[j] = max;
					nw.word_rank[j] = p->word;
				}
				else if (p->count == max&&p->word < nw.word_rank[j])
				{
					max_node = p;
					nw.word_rank[j] = p->word;
				}
			}
		}
		if (max == -1)
			break;
		if(max_node != NULL)
			max_node->count = -1;
		max = 0;
	}
}

int main(int argc,char *argv[])
{
	File fnew;
	Words wnew;
	Wordnode *log[HASH_LENGTH] = { NULL };
	int i;
	strcpy(fnew.file_name, argv[1]);
	cout << fnew.file_name<<endl;
	ifstream f;
	f.open(fnew.file_name, ios::in);
	if (!f.is_open())
	{
		cout << "can't open this file!" << endl;
	}
	fnew.count_chars = C_chars(f,fnew,wnew);
	fnew.count_words = C_words(f, wnew,log);

	//cout << "chars = " << fnew.count_chars << "," << "lines = " << fnew.count_lines<<","<<"words = "<<fnew.count_words<<endl;
	rank_word(log, wnew);

	ofstream fo;
	fo.open("result.txt", ios::out);
	if (!fo.is_open())
	{
		cout << "can't output the file!" << endl;
	}
	fo << "characters: " << fnew.count_chars << "\n";
	fo << "words: " << fnew.count_words << "\n";
	fo << "lines: " << fnew.count_lines << "\n";
	for (i = 1; i < 11; i++)
	{
		if (wnew.count_rank[i] != 0)
		{
			fo << "<" << wnew.word_rank[i] << ">: " << wnew.count_rank[i] << "\n";
		}
		else
			break;
	}
	system("pause");
	return 0;
}