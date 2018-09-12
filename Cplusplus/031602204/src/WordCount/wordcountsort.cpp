#include "stdafx.h"
#include "wordmaxsort.h"

void  sor(wd1 *f, int n)
{
	int w;
	for (int i = 0; i<n - 1; i++)
		for (int j = 0; j<n - i - 1; j++)
		{
			w = 0;
			while (f[j].s[w] == f[j + 1].s[w])
				w++;
			if (f[j].s[w] > f[j + 1].s[w])
				swap(f[j], f[j + 1]);
		}
}

void wordmax(char *tx)
{
	FILE *fp;
	fopen_s(&fp, tx, "r");

	if (fp == NULL)
	{
		cout << "该文件不存在！" << endl;
		return;
	}
	ofstream outf("H:\\result.txt", ios::app);

	wd1 temp, word[2000];
	int k, i, n = 0, j;

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

	sor(word, n);
	wd1 max[10];

	for (i = 0; i < 10; i++)//初始化前十名
	{
		max[i] = word[i];
	}

	for (j = 0; j < 10; j++)//前十名排序 
	{
		for (i = 0; i < 10 - j - 1; i++)
		{
			if (max[i].frq < max[i + 1].frq)
			{
				swap(max[i], max[i + 1]);
			}
		}
	}

	for (i = 10; i < n; i++)//找后面的数 
	{
		if (max[9].frq < word[i].frq)//比最小的还大 
		{
			int a = 8;
			while (max[a].frq < word[i].frq&&a >= 0)
			{
				a--;//定位到第一个比自己大的word
			}

			for (j = 9; j > a + 1; j--)
			{
				max[j] = max[j - 1];//前面的数后移一位 
			}
			if (a < 0)//说明word[i]比max[0]大
				max[0] = word[i];
			else
				max[j] = word[i];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (strlen(max[i].s) == 0)
			continue;
		outf << "<" << max[i].s << ">" << ":" << max[i].frq << endl;
	}
	outf.close();
}