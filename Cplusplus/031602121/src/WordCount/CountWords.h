#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cassert>
#include <algorithm>
using namespace std;
int CountWords(char *filename)
{
	ifstream in(filename);          //  ���ļ�
	if (!in)
	{
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}
	char word[10000];
	string ss;
	int WordNum=0;
	while (in.getline(word, 10000))         //   istream &in �����հ��ַ����ո�����Ʊ���ͻ��з�����ֹͣ���롣
	{
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
			
				WordNum++;//ͳ���ܵ�����
				i += count - 1;
			}
			else if (count>0 && count<4)i += count - 1;
			else continue;
		}

	}
	return WordNum;
}