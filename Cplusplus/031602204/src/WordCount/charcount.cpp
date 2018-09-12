#include "stdafx.h"
#include "charcount.h"

int charcount(char *tx)
{
	FILE *fp;
	int charcnt = 0;
	fopen_s(&fp,tx, "r");
	ofstream outf("H:\\result.txt");

	if (fp == NULL)
	{
		cout << "该文件不存在！" << endl;
		return 0;
	}

	while (!feof(fp))
	{
		char c = getc(fp);
		charcnt++;
	}
	outf << "characters:" << charcnt << endl;
	outf.close();
	return charcnt;
}