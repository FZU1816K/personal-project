#include "stdafx.h"
#include"linecount.h"

int linecount(char *tx)
{
	int flag = 1;
	int linecnt = 0;
	FILE *fp;
	int charcnt = 0;
	ofstream outf("H:\\result.txt", ios::app);

	fopen_s(&fp, tx, "r");

	if (fp == NULL)
	{
		cout << "该文件不存在！" << endl;
		return 0;
	}

	char c;
	while (!feof(fp))
	{
		c = getc(fp);

		if ((c != 10) && (c != ' ') && (c != EOF) && (flag == 1))
		{
			linecnt++;
			flag = 0;
		}

		if (c == 10)
		{
			flag = 1;
		}

	}
	outf << "lines:" << linecnt << endl;
	outf.close();
	return linecnt;
}