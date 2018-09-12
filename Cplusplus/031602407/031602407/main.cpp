#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
struct danci
{
	int num1 = 1;
	string content;
	int flag = 1;
};
danci word[500];
danci word1[500];
int num = 0;
int zhennum = 0;
bool cmp(danci x, danci y)
{
	if (x.num1 > y.num1)
		return true;
	else if (x.num1 == y.num1)
	{
		if (x.content > y.content)return false;
		else return true;
	}
	else
		return false;
}

void bigtosmall(string &x)
{
	for (unsigned int i = 0; i<x.size(); i++)
	{
		if (x[i] >= 'A'&&x[i] <= 'Z')
		{
			x[i] = x[i] + 32;
		}
	}
}
int main(int argc, char* argv[])
{
	int linenum = 0;//一行的字符数 
	int linenumber = 0;//几行 
	unsigned int i, j, r;
	if (argv[1] == NULL)
	{
		cout << "NO INPUT!" << endl;
	}
	ifstream file(argv[1]);
	if (!file)
	{
		cout << "Unable to open!" << endl;
	}
	string d;
	int count = 0, size;
	char pp[50];
	while (getline(file, d))
	{
		linenum = d.size() + 1;
		if (linenum != 1)
		{
			linenumber++;
		}
		count += linenum;
		bigtosmall(d);//大写转成小写
		//cout << count<<" "<<linenumber<<" "<<d << endl;
		for (i = 0; i < d.size(); i++)
		{
			if (d[i] >= 'a'&&d[i] <= 'z')
			{
				size = 0;
				pp[size] = d[i]; size++;
				for (j = i + 1; j < d.size(); j++)
				{
					if (d[j] >= 'a'&&d[j] <= 'z')
					{
						//cout << d[j];
						pp[size] = d[j];
						size++;
					}
					else
					{
						break;
					}
				}
				//cout << pp << endl;
				if (size >= 4)
				{
					for (r = j; r < d.size(); r++)
					{
						if (d[r] != ' ')
						{
							pp[size] = d[r]; size++;
						}
						else
						{
							i = r; pp[size] = '\0';
							word[num].content = pp;
							break;
						}
						if (r == d.size() - 1)
						{
							pp[size] = '\0';
							word[num].content = pp; i = r;
						}
					}
					if (j >= d.size())
					{
						i = j; pp[size] = '\0';
						word[num].content = pp;
					}
					num++;
				}
				else
				{
					i = j;
				}
			}
		}
	}
	/*for (i = 0; i < num; i++)
	{
		cout << word[i].num1 << " " << word[i].content << endl;
	}*/
	int ii,jj;
	for (ii = 0; ii < num; ii++)
	{
		if (word[ii].flag == 0)
		{
			continue;
		}
		for (jj = 0; jj < num; jj++)
		{
			if (ii == jj)continue;
			if (word[ii].content == word[jj].content)
			{
				word[ii].num1++;
				word[jj].flag = 0;
			}
		}
	}
	for (ii = 0; ii < num; ii++)
	{
		if (word[ii].flag == 1)
		{
			word1[zhennum] = word[ii]; zhennum++;
		}
	}
	sort(word1, word1 + zhennum, cmp);
	cout << "characters:" << count << endl;
	cout << "words:" << zhennum << endl;
	cout << "lines:" << linenumber << endl;
	if (zhennum >= 10)
	{
		for (ii = 0; ii < 10; ii++)
		{
			cout << word1[ii].content << ":" << word1[ii].num1 << endl;
		}
	}
	else
	{
		for (ii = 0; ii < zhennum; ii++)
		{
			cout << word1[ii].content << ":" << word1[ii].num1 << endl;
		}
	}
}
