#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<cassert>
#include <algorithm>
using namespace std;
const int K = 10;
bool cmp(int a, int b)
{
	return a>b;
}
void adjustDown(vector<map<string, int>::iterator> &top, int i)
{
	int min = i;
	int child = 2 * min + 1;
	while (i < K / 2)
	{
		if ((child + 1 < K) && (top[child]->second > top[child + 1]->second))
			child++;
		if ((child<K) && (top[min]->second>top[child]->second))
		{
			swap(top[min], top[child]);
			min = child;
			child = 2 * min + 1;
		}
		else
			break;
	}
}
void topK(map<string, int> &essay, vector<map<string, int>::iterator> &top)
{
	auto it = essay.begin();
	//  初始化完全二叉树
	for (int i = 0; i < K; i++)
	{
		top[i] = it;
		it++;
	}
	//  建立小根堆
	for (int i = K / 2 - 1; i >= 0; i--)
	{
		adjustDown(top, i);
	}
	//  取topK
	while (it != essay.end())
	{
		if (it->second > top[0]->second)
		{
			top[0] = it;                     //  大于堆顶元素，则入堆；
			adjustDown(top, 0);              //  重新调整为小根堆；

		}
		it++;
	}
	int a[10], temp;
	string b[10], temp1;

	for (int i = K - 1; i >= 0; i--)
	{
		a[i] = essay[top[0]->first];
		b[i] = top[0]->first;
		top[0]->second = 1000000;
		adjustDown(top, 0);              //  重新调整为小根堆；
	}
	sort(a, a + 10, cmp);
	for (int i = 0; i < 10; i++)
	{
		cout <<"<" << b[i] << ">: " << a[i] << endl;
	}
}
int main()
{
	int num = 0, j = 0,p = 0;
	ifstream in("test.txt");          //  打开文件
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
	char word[1000];
	string ss;
	map<string, int> essay;
	while (in.getline(word, 1000))         //   istream &in 遇到空白字符（空格符、制表符和换行符）即停止读入。
	{
		num++;//统计行数
		ss = word;
		for (int i = 0; i < ss.length(); i++)//对每行的操作
		{
			int count = 0;
			for (int k = i;; k++)//判断是否符合需求中单词的样子
			{

				if (ss[k] >= 'a'&&ss[k] <= 'z')
					count++;
				else if (ss[k] >= 'A'&&ss[k] <= 'Z')
				{
					count++;

				}
				else if (ss[k] >= '0'&&ss[k] <= '9'&&count >= 4)
					count++;
				else break;
			}
			if (count >= 4) //若符合要求，则记录
			{
				char words[100] = { '\0' };
				for (int k = i; k < i + count; k++)
				{
					words[k - i] = ss[k];
				}
				string s;
				s = words;
				essay[s]++;
				p++;//统计总单词数
				i += count - 1;
			}
			else if (count>0 && count<4)i += count - 1;
			else continue;
		}
		j += ss.length();//统计字符数
	}
	cout << "characters：" << j << endl << "words: " << p<<endl << "lines: " << num << endl;
	vector < map<string, int> ::iterator> top(K, essay.begin());
	topK(essay, top);
	getchar();
	getchar();
	return 0;
}