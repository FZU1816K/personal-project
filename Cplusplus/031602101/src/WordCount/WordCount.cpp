#include"stdafx.h"
#define _CRT_SECURE_NO_DEPRECATE；
#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)；
using namespace std;
#define M 20000
typedef struct
{
	char danci[19];//储存单词
	int count;//记录单词个数,后面出现几次
}sq;

void wordsta(FILE *fp, sq t_word, sq *word)  //统计单词频数
{
	int characters = 0, lines = 0, numberC = 0;
	int i, j, K, n=0;
	while (!feof(fp))//feof()检测是否达到文件尾部
	{
		char ch;
		ch = getc(fp);//获取当前字符
		characters++;
		if (ch == ' ' || ch == 10)
		{//ASCLL码中10为换行符，此条件为遇到空格或回车则跳过
			if (ch == 10)
			{
				lines++;
			}//判断行数
			continue;
		}
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))              //发现一个单词
		{
			K = 0;
			t_word.count = 1;
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch == '\''))
			{
				if (ch >= 'A'&&ch <= 'Z')
					ch += 32;//转换成小写
				t_word.danci[K++] = ch;//把当前字母存入数组
				ch = getc(fp);
				characters++;
			}
			t_word.danci[K++] = '\0';//结束标志\0
			if (K <= 4)
			{
				continue;
			}
			numberC++;
			//一个单词结束
			j = n;
			for (i = 0; i < j; i++) //与前面的单词比较
			{
				if (strcmp(t_word.danci, word[i].danci) == 0)//如果有单词相同
				{
					word[i].count++;//则此类单词加1
					break;
				}
			}
			if (n == 0 || i == j)//前面如果没有相同的单词
			{
				word[n] = t_word;//则为此类单词开辟新单元
				n++;
			}
		}
	}
	cout << "characters" << characters << endl;
	cout << "words" << numberC << endl;
	cout << "lines" << lines << endl;
}
sq* namemath(sq *word) //利用冒泡法排序前十单词
{
	int i, j, n=0;
	sq *frequency_max = new sq[11];
	sq temp;
	for (i = 0; i<10; i++)
	{
		frequency_max[i] = word[i];//初始化频率最高的十个单词为前十个单词
	}
	//冒泡排序法
	for (j = 0; j<10; j++)
		for (i = 0; i<10 - j; i++)
			if (frequency_max[i].count<frequency_max[i + 1].count)
			{
				temp = frequency_max[i];
				frequency_max[i] = frequency_max[i + 1];
				frequency_max[i + 1] = temp;
			}
	for (i = 10; i<n; i++)
	{
		if (frequency_max[9].count<word[i].count)
		{
			int a = 8;
			while (frequency_max[a].count<word[i].count&&a >= 0)
			{
				a--;
			}


			for (j = 9; j>a + 1; j--)
			{
				frequency_max[j] = frequency_max[j - 1];
			}
			if (a<0)
				frequency_max[0] = word[i];
			else
				frequency_max[j] = word[i];
		}
	}
	return frequency_max;
}
void main(int arg,char* argv[])
{
	int i;
	sq *word=new sq[M];
	sq t_word = {0,0};
	FILE *fp;
	fp = fopen(argv[1], "r");
	cout << argv[1] << endl;
	if (!fp) cout << "error" << endl;
	cout << "统计文件下频率最高的十个单词"<<endl;
	wordsta(fp, t_word, word);
	sq* frequency_max= namemath(word);
	for (i = 0; i<10; i++)
	{
		cout << setiosflags(ios::left) << setw(10) << frequency_max[i].danci << frequency_max[i].count << endl;//setw()设置输出域宽，默认右对齐
	}
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
}