#include"stdafx.h"
void charcounter(char ch, int &characters)
{
	if (ch >= ' '&&ch <= '~')
	{
		characters++;
	}
}
void linecounter(char ch, int &lines)
{
	if (ch == '\n')
		lines++;
}
void wordcounter(char ch, int &flag, int &words, char testword[])
{
	if (ch >= ' '&&ch <= '~')
	{
		if (ch >= 65 && ch <= 90)
		{
			ch = ch + 32;
		}
		if (ch >= 87 && ch <= 122 && flag <= 3)
		{
			flag++;
			testword[flag] = ch;
		}
		if ((ch < 87 || ch>122) && flag <= 3)
		{
			flag = 0;
		}
		if (flag >= 4 && ch != ' ')
		{
			flag++;
			testword[flag] = ch;
		}
		if (flag >= 4 && ch == ' ')
		{
			words++;
		}
	}
}
int min(int a, int b)
{
	if (a >= b)
	{
		return b;
	}
	else return a;
}
