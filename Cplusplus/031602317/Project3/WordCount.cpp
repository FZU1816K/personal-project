#include "stdafx.h"
FILE *fp;
using namespace std;
int main()
{
	int lines = 0, characters = 0, words = 0;
	char ch;
	char filename[1000];
	char testword[1000];
	int flag = 0;
	int kind = 0;
	int temp = 0;
	int i, j, k;
	Words type[1000];
	cout << "请输入文本的路径" << endl;
	cin >> filename;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		cout << "路径输入错误" << endl;
		exit(0);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		charcounter(ch, characters);
		wordcounter(ch, flag, words, testword);
		if (ch >= ' '&&ch <= '~')
		{
			if (flag >= 4 && ch == ' ')
			{
				for (i = 1; i <= kind; i++)
				{
					for (j = 1; j <= flag; j++)
					{
						if (testword[j] != type[i].wordtype[j])
						{
							i++;
							j = 1;
							break;
						}
						if (j == flag)
						{
							type[i].frequency++;
							i = kind;
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
		linecounter(ch, lines);
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	cout << endl;
	cout << "characters: " << characters << endl;
	cout << "words: " << words << endl;
	cout << "lines: " << lines + 1 << endl;
	int tra = 1;
	int max = type[1].frequency;
	int len = type[1].lenth;
	for (i = 1; i <= min(10, kind); i++)
	{
		for (j = 2; j <= kind; j++)
		{
			if (type[j].frequency == max)
			{
				for (k = 1; k <= min(type[j].lenth, len); k++)
				{
					if (type[j].wordtype[k] < type[tra].wordtype[k])
					{
						tra = j;
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
		cout << "<";
		for (k = 1; k <= type[tra].lenth; k++)
		{
			if (k == 4)
			{
				continue;
			}
			cout << type[tra].wordtype[k];
		}
		cout << ">:";
		cout << type[tra].frequency << endl;
		type[tra].frequency = 0;
		max = 0;
		type[tra].lenth = 10000000;
	}
	system("pause");
}
