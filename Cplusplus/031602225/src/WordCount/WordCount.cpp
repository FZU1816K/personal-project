
#include "stdafx.h"
#include<iostream>
#include<string>
#include<queue>
#include<stdio.h>
#include<fstream>



using namespace std;

int characters = 0;
int words = 0;

typedef struct {
	char word[50];
	int count;
}wo;


priority_queue<wo> tmp;//优先队列


int countLines(string u) //统计行数
{
	int lines = 0;

	ifstream fin;
	fin.open(u);//打开文件

	if (!fin)
	{
		cout << "can not open file" << endl;
	}

	string s;
	while (getline(fin, s))lines++;//行遍历一遍，计算行数

	fin.close();

	return lines;
}


void countChar(string u)//统计字符数、单词放在全局变量、优先队列中
{
	wo *danci = new wo[9999999];//动态分配结构体数组
	wo temp_danci;

	int k, i, j, flag,n=0;


	char ch;

	ifstream fin;
	fin.open(u);//打开文件

	if (!fin)
	{
		cout << "can not open file" << endl;
	}

	while (!fin.eof())
	{
		ch = fin.get();
		characters++;


		//判断是否为单词
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		{
			k = 0;
			flag = 0;
			temp_danci.count = 1;

			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
			{
				if (ch >= 'A'&&ch <= 'Z')
					ch += 32;

				temp_danci.word[k++] = ch;
				ch = fin.get();
				characters++;
			}
			temp_danci.word[k++] = '\0';


			for (i = 0; i < 4; i++)
			{
				if ((temp_danci.word[i] >= '0'&&temp_danci.word[i] <= '9') || temp_danci.word[i] == '\0')
				{
					flag = 1;//判断是否符合单词规范
					break;
				}
			}


			if (flag == 0)
			{
				words++;
				j = n;


				for (i = 0; i<j; i++)//相同的单词个数累加
				{
					if (strcmp(temp_danci.word, danci[i].word) == 0)

					{
						danci[i].count++;

						break;
					}


				}


				if (n == 0 || i == j)//新单词生成新的空间

				{
					danci[n] = temp_danci;

					n++;
				}

			}

		}

		else continue;



	}
	fin.close();

	for (int i = 0; i < n; i++)
	{
		tmp.push(danci[i]);
	}


}


bool operator< (wo a, wo b)//自定义排序
{
	//个数相同的单词按字典排序
	if (a.count == b.count)
	{
		int i = -1;

		do {
			i++;
		} while (a.word[i] == b.word[i]);
		
		return a.word[i] > b.word[i];

	}
	//出现频率排序	
	else return a.count < b.count;

}


void print(string u)//输出到文件
{
	int x = 0;
	ofstream outf;
	outf.open("result.txt");

	outf << "characters: " << characters-1 << endl;
	outf << "words: " << words << endl;
	outf << "lines: " << countLines(u) << endl;

	while (!tmp.empty() && x<10)//输出前十个单词
	{
		outf << "<" << tmp.top().word << ">: " << tmp.top().count << endl;
		tmp.pop();
		x++;
	}
	outf.close();
}


int main() {

	string url;
	cin >> url;
	
	countChar(url);

	print(url);
	
	return 0;
}
