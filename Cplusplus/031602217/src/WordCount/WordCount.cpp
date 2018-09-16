#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Characters(char filename[100])
{
	FILE *fp = NULL;
	char ch;
	int characters = 0;
	fp = fopen(filename, "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == -1)break;
		characters++;
	}
	printf("characters:%d\n", characters);
	FILE *ffp = fopen("result.txt", "w");
	fprintf(ffp, "characters:%d\n", characters);
	fclose(fp);
	fclose(ffp);
}

void Lines(char filename[100])
{
	FILE *fp = NULL;
	char ch;
	int lines = 0, changeline = 1;
	fp = fopen(filename, "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == -1)
		{
			if (changeline == 0)lines++;
			break;
		}
		if (ch == '\n'&&changeline == 0)
		{
			changeline = 1;
			lines++;
		}
		if (changeline == 1 && ch != '\n'&&ch != ' '&&ch != '	')changeline = 0;
	}
	printf("lines:%d\n", lines);
	FILE *ffp = fopen("result.txt", "a");
	fprintf(ffp, "lines:%d\n", lines);
	fclose(fp);
	fclose(ffp);
}

void Words(char filename[100])
{
	FILE *fp = NULL;
	char ch;
	int length = 0, words = 0;
	fp = fopen(filename, "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == -1)
		{
			if (length >= 4)words++;
			break;
		}
		if (ch >= 65 && ch <= 90)ch = ch + 32;
		if (ch >= 97 && ch <= 122)length++;
		else if (ch >= 48 && ch <= 57 && length >= 4)length++;
		else
		{
			if (length >= 4)words++;
			length = 0;
		}
	}
	printf("words:%d\n", words);
	FILE *ffp = fopen("result.txt", "a");
	fprintf(ffp, "words:%d\n", words);
	fclose(fp);
	fclose(ffp);
}

void TopWords(char filename[100])
{
	FILE *fp = NULL;
	char ch, now[20];
	int length = 0, sum = 0, flag = 0, t, i, j;
	struct Word
	{
		char name[20];
		int count;
	};
	struct Word w[10000];
	for (i = 0; i < 10000; i++)w[i].count = 0;
	fp = fopen(filename, "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == -1)
		{
			if (length >= 4)
			{
				flag = 0;
				now[length] = '\0';
				for (i = 0; i < sum; i++)
				{
					if (strcmp(w[i].name, now) == 0)
					{
						w[i].count++;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					strcpy(w[sum].name, now);
					w[sum].count++;
					sum++;
				}
			}
			break;
		}
		if (ch >= 65 && ch <= 90)ch = ch + 32;
		if (ch >= 97 && ch <= 122)
		{
			now[length] = ch;
			length++;
		}
		else if (ch >= 48 && ch <= 57 && length >= 4)
		{
			now[length] = ch;
			length++;
		}
		else
		{
			if (length >= 4)
			{
				flag = 0;
				now[length] = '\0';
				for (i = 0; i < sum; i++)
				{
					if (strcmp(w[i].name, now) == 0)
					{
						w[i].count++;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					strcpy(w[sum].name, now);
					w[sum].count++;
					sum++;
				}
			}
			length = 0;
		}
	}
	for (j = 0; j < 10 && j < sum; j++)
		for (i = sum - 1; i > j; i--)
		{
			if ((w[i].count > w[i - 1].count) || ((w[i].count == w[i - 1].count) && (strcmp(w[i].name, w[i - 1].name) == -1)))
			{
				t = w[i].count;
				w[i].count = w[i - 1].count;
				w[i - 1].count = t;
				strcpy(now, w[i].name);
				strcpy(w[i].name, w[i - 1].name);
				strcpy(w[i - 1].name, now);
			}
		}
	FILE *ffp = fopen("result.txt", "a");
	for (i = 0; i < 10 && i < sum; i++)
	{
		printf("<%s>:%d\n", w[i].name, w[i].count);
		fprintf(ffp, "<%s>:%d\n", w[i].name, w[i].count);
	}
	fclose(fp);
	fclose(ffp);
}

int main()
{
	FILE *FP = NULL;
	char filename[100];
	printf("请输入欲读取的文件名：");
	scanf("%s", filename);
	if ((FP = fopen(filename, "r")) == NULL)
	{
		printf("打开文件错误");
		return 0;
	}
	fclose(FP);
	Characters(filename);
	Words(filename);
	Lines(filename);
	TopWords(filename);
	return 0;
}
