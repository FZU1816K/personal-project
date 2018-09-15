#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cassert>
#include <algorithm>
using namespace std;
const int K = 10;
bool cmp(int a, int b)
{
	return a>b;
}
void adjustDown(vector<unordered_map<string, int>::iterator> &top, int i)
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
void topK(unordered_map<string, int> &essay, vector<unordered_map<string, int>::iterator> &top, ofstream &fout)
{
	auto it = essay.begin();
	//  ��ʼ����ȫ������
	for (int i = 0; i < K; i++)
	{
		top[i] = it;
		it++;
	}
	//  ����С����
	for (int i = K / 2 - 1; i >= 0; i--)
	{
		adjustDown(top, i);
	}
	//  ȡtopK
	while (it != essay.end())
	{
		if (it->second > top[0]->second)
		{
			top[0] = it;                     //  ���ڶѶ�Ԫ�أ�����ѣ�
			adjustDown(top, 0);              //  ���µ���ΪС���ѣ�

		}
		it++;
	}
	int a[10];
	string b[10];

	for (int i = K - 1; i >= 0; i--)
	{
		a[i] = essay[top[0]->first];
		b[i] = top[0]->first;
		top[0]->second = 1000000;
		adjustDown(top, 0);              //  ���µ���ΪС���ѣ�
	}
	sort(a, a + 10, cmp);
	fout.open("result.txt", ios::app);
	for (int i = 0; i < 10; i++)
	{
		fout << "<" << b[i] << ">: " << a[i] << endl;
	}
	fout.close();
}
void CountWF(char *filename, ofstream &fout)
{
	int num = 0;
	ifstream in(filename);          //  ���ļ�
	if (!in)
	{
		cerr << "�޷��������ļ�" << endl;
		exit(0);
	}
	char word[10000];
	string ss;
	unordered_map<string, int> essay;
	while (in.getline(word, 10000))         //   istream &in �����հ��ַ����ո�����Ʊ���ͻ��з�����ֹͣ���롣
	{
		//num++;//ͳ������
		ss = word;
		for (int i = 0; i < ss.length(); i++)//��ÿ�еĲ���
		{
			int count = 0;
			for (int k = i;; k++)//�ж��Ƿ���������е��ʵ�����
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
			if (count >= 4) //������Ҫ�����¼
			{
				char words[100] = { '\0' };
				
				for (int k = i; k < i + count; k++)
				{
					words[k - i] = ss[k];
					
				}
				string s;
				s = words;
				essay[s]++; num++;
				i += count - 1;
			}
			else if (count>0 && count<4)i += count - 1;
			else continue;
		}

	} 
	if (num < 10) 
	{ 
		cout << "�ı��в�ͬ�ĵ��ʲ���10�����޷�ͳ��ǰʮ��Ƶ" << endl;
	}
	else
	{
		vector < unordered_map<string, int> ::iterator> top(K, essay.begin());
		topK(essay, top, fout);
	}
}