#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <regex>
#include <algorithm>
#define MAXLENGTH   101


//https://blog.csdn.net/nichengwuxiao/article/details/78789225
//https://www.cnblogs.com/batman425/p/3179520.html
//https://www.cnblogs.com/hexiaobao/p/8134829.html

using namespace std;


struct node { //链表结构体
	string name;//单词名
	int times;//单词出现频次
	node *next;
	node(string n, int number) //构造函数
	{
		name = n;
		times = number;
		next = NULL;
	}
};



struct files
{
	char file_path[MAXLENGTH];
	char file_name[MAXLENGTH];
	int chars_cnt;
	int words_cnt;
	int lines_cnt;
	node *hash_table[18280];//哈希表

	files()
	{
		file_path[0] = '\0';
		file_name[0] = '\0';
		chars_cnt = 0;
		words_cnt = 0;
		lines_cnt = 1;
		for (int i = 0; i <= 18279; i++)//初始化整个结构体指针数组
		{
			hash_table[i] = new node("", 0);
		}
	}
};

struct words
{
	string allwords;
	int rank_cnt[11];
	string rank_name[11];
	words()
	{
		allwords = "";
		for (int i = 0; i < 11; i++)
		{
			rank_cnt[i] = 0;
			rank_name[i] = "";
		}
	}
};





int chars_counter(istream &f, files &fn, words &wn)
{
	char temp;
	int cnt = 0;
	while (!f.eof())
	{
		f.get(temp);
		if ((temp <= 126 && temp >= 32) || temp == 9 || temp == 10)
		{
			wn.allwords += temp;
			cnt++;
		}
	}

	return cnt;
}

int lines_counter(istream &f, files &fn, words &wn)
{
	int flag = 0;
	int cnt = 0;
	int len = wn.allwords.length();//文本长度
	for (int i = 0; i < len; i++)
	{
		if (wn.allwords[i] >= 33 && wn.allwords[i] <= 126)//表示该行是有效行
		{
			flag = 1;
			continue;
		}
		if (wn.allwords[i] == 10 && flag == 1)//当该行是有效行，并且遍历到1个换行符时，行数加1
		{
			cnt++;
			flag = 0;
		}
	}
	if (flag == 1)//最后一行如果没有换行符，也要加1
		cnt++;

	return cnt;
}



void insert(files &fn, string w)//把单词插入哈希表
{
	int hash = ((w[0] - 96)) + ((w[1] - 96) * 26) + ((w[2] - 96) * 26 * 26);//计算哈希值
	node *p = new node("", 1);
	node *q = new node("", 1);
	if (fn.hash_table[hash]->next == NULL)//空表插入
	{
		p = fn.hash_table[hash];
		fn.hash_table[hash] = new node(w, 1);
		fn.hash_table[hash]->next = p;
	}
	else//非空表
	{
		int flag = 0;
		q = p = fn.hash_table[hash];
		while (p->next != NULL)//遍历链表
		{
			if (p->name == w)//在表中找到该单词，并且times加1
			{
				p->times++;
				flag = 1;
			}
			q = p;
			p = p->next;
		}
		if (flag == 0)//在链表中没有找到该单词，则在链表尾部插入新结点
		{
			node *newnode = new node(w, 1);
			q->next = newnode;
			newnode->next = p;
		}
	}
	return;
}


void file_rank(files &fn)//统计词频
{
	int num;
	int flag = 0;//判断出现次数最大的结点是不是表首 0不是 1是
	node *max, *q, *p, *front_max;
	front_max = new node("", 0);
	for (int j = 0; j < 10 && j < fn.words_cnt; j++)//遍历10次哈希表
	{
		max = new node("", 0);//初始化max
		for (int i = 0; i <= 18279; i++)
		{
			if (fn.hash_table[i]->next == NULL) continue;//空表跳过
			else//非空表
			{
				q = p = fn.hash_table[i];
				while (p->next != NULL)
				{
					if (p->times > max->times || (p->times == max->times&&p->name < max->name))
					{

						if (p == fn.hash_table[i])
						{
							flag = 1;//表示该单词在表头
							num = i;
						}
						else flag = 0;//表示该单词在表中
						max = p;
						front_max = q;
					}
					q = p;
					p = p->next;
				}
			}
		}
		if (max->times != 0)
		{
			cout << "<" << max->name << ">:" << max->times << endl;//输出一个结果
			//*outfile << "<" << max->name << ">:" << max->times << endl;//输出一个结果
		}
		else  break;//如果max没有被替换，则此时哈希表是空的，不需要输出

		if (flag == 1)	fn.hash_table[num] = max->next;//如果频次最大的单词在表首，替换表首指针
		else front_max->next = max->next;//如果频次最大的单词在表中，删除结点
	}
	return;
}



int words_counter(ifstream &f, files &fn, words &wn)
{
	int flag = 0;
	string temp = "";
	int len = wn.allwords.length();
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if ((wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122))//找到第一个字母  判断是不是单词
		{
			flag = 0;
			for (int j = i; j <= i + 3; j++)
			{
				if (wn.allwords[j] <= 64 || (wn.allwords[j] >= 91 && wn.allwords[j] <= 96) || wn.allwords[j] >= 123 || len - i < 4)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)//如果是单词就提取单词到temp
			{
				temp = "";
				for (; i < len && ((wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122) || (wn.allwords[i] >= 48 && wn.allwords[i] <= 57)); i++)
				{
					if (wn.allwords[i] >= 65 && wn.allwords[i] <= 90)
						wn.allwords[i] += 32;
					temp += wn.allwords[i];
				}
				cnt++;
				insert(fn,temp);
				//cout << temp << endl;
			}
			else//如果不是单词就跳到下一个单词的第一个字母
			{
				for (; (wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122); i++) {}
			}
		}
		else if (wn.allwords[i] >= 48 && wn.allwords[i] <= 57)
		{
			for (; (wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122) || (wn.allwords[i] >= 48 && wn.allwords[i] <= 57); i++) {}
		}
	}

	return cnt;
}





int main(int argc, char *argv[])
{
	ifstream f;
	files file_input;
	words word;
	


		
	strcpy(file_input.file_name, argv[1]);
	cout << file_input.file_name << endl;

	f.open(file_input.file_name, ios::in);
	if (!f.is_open())
	{
		cout << "Warning! can't open this file!" << endl;
	}

	file_input.chars_cnt = chars_counter(f, file_input, word);
	file_input.lines_cnt = lines_counter(f, file_input, word);
	file_input.words_cnt = words_counter(f, file_input, word);
	file_rank(file_input);
	
	cout << file_input.chars_cnt << endl;
	cout << file_input.lines_cnt << endl;
	cout << file_input.words_cnt << endl;

	system("pause");
	return 0;
}
