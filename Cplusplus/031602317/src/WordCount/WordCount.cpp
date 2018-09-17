#include"stdafx.h"
#include <iostream>
#include <vector>
#include <fstream> 
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using   std::string;
using   std::vector;
using namespace std;
struct cube
{
	char wordtype[1000];
	int frequency = 0;
	int lenth;
};
cube type[40000];
int min(int a, int b)
{
	if (a >= b)
	{
		return b;
	}
	else return a;
}
class tools {
public:tools(vector<char> cha) { ch = cha; }
	   int wordcounter(int &kind, cube type[]);
	   int linecounter();
	   int charcounter();
	   void wordprinter(int &kind, cube type[], int print[], int pront[]);
private:
	vector<char> ch;
};
int tools::linecounter()
{
	int count = 0;
	int i;
	for (i = 1; i <= ch.size(); i++)
	{
		if (ch[i] == '\n')
			count++;
	}
	return count + 1;
}
int tools::charcounter()
{
	int count = 0;
	int i;
	for (i = 0; i < ch.size(); i++)
	{
		count++;
	}
	return count - 2;
}
int tools::wordcounter(int &kind, cube type[])
{
	int count = 0;
	int i, j, k, p;
	int flag = 0;
	int temp = 0;
	char testword[100];
	for (i = 0; i <= ch.size(); i++)
	{
		if (ch[i] >= 'A'&& ch[i] <= 'Z')
		{
			ch[i] = ch[i] + 32;
		}
		if (ch[i] >= 'a' && ch[i] <= 'z' && flag <= 3)
		{
			flag++;
			testword[flag] = ch[i];
		}
		if ((ch[i]<'a' || ch[i]>'z') && flag <= 3)
		{
			flag = 0;
		}
		if (flag >= 4 && (ch[i] >= '0'&&ch[i] <= '9' || ch[i] >= 'a'&&ch[i] <= 'z'))
		{
			flag++;
			testword[flag] = ch[i];
		}
		if (flag >= 4 && (ch[i]<'0' || ch[i]>'9'&&ch[i]<'a' || ch[i]>'z'))
		{
			count++;
			for (p = 1; p <= kind; p++)
			{
				for (j = 1; j <= flag; j++)
				{
					if (testword[j] != type[p].wordtype[j])
					{
						p++;
						j = 1;
						break;
					}
					if (j == flag)
					{
						type[p].frequency++;
						p = kind;
						temp = 1;
						break;
					}
				}
			}
			if (temp == 0)
			{
				kind++;
				for (k = 1; k <= flag; k++)
				{
					type[kind].wordtype[k] = testword[k];
				}
				type[kind].lenth = flag;
				type[kind].frequency++;
			}
			flag = 0;
			temp = 0;
		}
	}
	return count;
}
void tools::wordprinter(int &kind, cube type[], int print[], int pront[])
{
	int i, j, k;
	int l = 0;
	int tra = 0;
	int max = 0;
	int len = 100000;
	for (i = 1; i <= min(kind, 10); i++)
	{
		for (j = 1; j <= kind; j++)
		{
			if (type[j].frequency == max)
			{
				for (k = 1; k <= min(type[j].lenth, len); k++)
				{
					if (type[j].wordtype[k] < type[tra].wordtype[k])
					{
						tra = j;
						len = type[j].lenth;
						break;
					}
					if (type[j].wordtype[k] > type[tra].wordtype[k])
					{
						break;
					}
					if (k == min(type[j].lenth, len))
					{
						if (type[j].lenth < len)
						{
							tra = j;
							len = type[j].lenth;
						}
					}
				}
			}
			if (type[j].frequency > max)
			{
				max = type[j].frequency;
				tra = j;
			}
		}
		print[l++] = type[tra].frequency;
		pront[l] = tra;
		//	cout << "<";
		//for (k = 1; k <= type[tra].lenth; k++)
		//{
		//	if (k == 4)
		//	{
		//		continue;
		//	}
		//		cout << type[tra].wordtype[k];
	//	}
		//cout << ">:";
		//cout <<" "<<type[tra].frequency << endl;
		type[tra].frequency = 0;
		len = 100000;
		max = 0;
	}
}
int main()
{
	ifstream infile;
	ofstream outfile;
	vector<char>words;
	char ch;
	string pi[10];
	char filename[100];
	int print[100];
	int pront[100];
	int kind = 0;
	int q, i;
	cout << "请输入测试文本地址：";
	cin >> filename;
	infile.open(filename);
	if (!infile)
	{
		cout << "读入文件不存在" << endl;
	}
	infile >> noskipws;
	if (infile.is_open())
	{
		while (infile.good() && !infile.eof())
		{
			infile >> ch;
			words.push_back(ch);
		}
		words.push_back(' ');
	}
	infile.close();
	tools t(words);
	outfile.open("result.txt");
	outfile << "characters: " << t.charcounter() << endl;
	outfile << "words: " << t.wordcounter(kind, type) << endl;
	outfile << "lines: " << t.linecounter() << endl;
	t.wordprinter(kind, type, print, pront);
	for (q = 0; q < 10; q++)
	{
		outfile << "<";
		for (i = 1; i <= type[pront[q + 1]].lenth; i++)
		{
			if (i == 4)
			{
				continue;
			}
			outfile << type[pront[q + 1]].wordtype[i];
		}
		outfile << ">: " << print[q] << endl;
	}
	//  t.charcounter();
	//  t.wordcounter(kind,type);
	//  t.linecounter();
	//  t.wordprinter(kind,type);
	outfile.close();
	return 0;
}