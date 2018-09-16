
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<cstring>
#include<string.h>
#include"fengzhuang.h"
using namespace std;
struct danci
{
	int num1 = 1;
	string content;
	int flag = 1;
};
danci word[10000];
danci word1[10000];
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

int main(int argc, char* argv[])
{
	int linenum = 0;//一行的字符数 
	int linenumber = 0;//几行 
	int i, j, r;
	if (argv[1] == NULL)
	{
		cout << "NO INPUT!" << endl;
	}
	ifstream file(argv[1]);
	if (!file)
	{
		cout << "UNABLE TO OPEN!" << endl;
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
				}//cout << size << endl;
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
	for (i = 0; i < num; i++)
	{
		if (word[i].flag == 0)
		{
			continue;
		}
		for (j = 0; j < num; j++)
		{
			if (i == j)continue;
			if (word[i].content == word[j].content)
			{
				word[i].num1++;
				word[j].flag = 0;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		if (word[i].flag == 1)
		{
			word1[zhennum] = word[i]; zhennum++;
		}
	}
	sort(word1, word1 + zhennum, cmp);
	ofstream outfile;
	outfile.open("result.txt");
	outfile << "characters: " << count-1 << endl;
	outfile << "words: " << num << endl;
	outfile << "lines: " << linenumber << endl;
	if (zhennum >= 10)
	{
		for (i = 0; i < 10; i++)
		{
			outfile <<"<"<< word1[i].content << ">: " << word1[i].num1 << endl;
		}
	}
	else
	{
		for (i = 0; i < zhennum; i++)
		{
			outfile <<"<"<< word1[i].content << ">: " << word1[i].num1 << endl;
		}
	}
	outfile.close();
}

