#include "stdafx.h"
#include "wordcount.h"

int wordcount(char *tx)
{
	int wordcnt = 0, j, n = 0;
	wd temp, word[2000];
	int k, i;
	ofstream outf("H:\\result.txt", ios::app);

	FILE *fp;
	fopen_s(&fp, tx, "r");

	if (fp == NULL)
	{
		cout << "该文件不存在！" << endl;
		return 0;
	}

	while (!feof(fp))
	{
		char c = getc(fp);
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))//可能是单词 
		{
			k = 0;
			temp.frq = 1;
			while ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9'&&k >= 4))//继续后几位的验证 
			{
				if (c >= 'A'&&c <= 'Z')
				{
					c = c + 32;
				}
				temp.s[k] = c;
				k++;

				c = getc(fp);
			}
			temp.s[k] = '\0';//单词结束标识 
			k++;

			j = n;

			if (strlen(temp.s) >= 4)//确保大于4位英文字母 
			{
				wordcnt++;
				for (i = 0; i < j; i++)
				{
					if (strcmp(temp.s, word[i].s) == 0)//归于之前的 
					{
						word[i].frq++;
						break;
					}
				}

				if (n == 0 || i == j)
				{
					word[n] = temp;
					n++;
				}
			}
		}
	}
	outf << "words:" << wordcnt << endl;
	outf.close();
	return wordcnt;
}