#pragma once
#include<iostream>
#include<string>
using namespace std;
class Top_Ten											//ǰʮ��Ƶ����ߵĵ���һ��Top_Ten����
{
public:
	int number;
	string word;
	Top_Ten()
	{
		number = 0;
		word = "";
	};
	~Top_Ten()
	{}
	friend  ostream  &operator <<(ostream &os, const Top_Ten &stu);
};
ostream  &operator<<(ostream &os, const Top_Ten &top_ten);

bool Cmp(const Top_Ten& top1, const Top_Ten& top2);		//�Զ���ȽϺ���;
/**
***		���ܣ�sort������Top_Ten������ʱ���Զ���������
***			  ���ղ�ͬ���ʳ���Ƶ���Ӵ�С����Ƶ��һ��
***			  ʱ�����ֵ�������
**/

bool Is_Engch(char ch);
/**
***		���ܣ��ж��ַ��Ƿ���Ӣ����ĸ
**/

bool Is_Num(char ch);
/**
***		���ܣ��ж��ַ��Ƿ�������
**/
string Is_Word(string word);
/**
***		���ܣ��ж��ַ����Ƿ�����Ҫ��ĸ�ʽ�ĵ���
**/
void Top_Tenwords(Top_Ten words[],char *filename);
/**
***		���ܣ��ҳ�Ƶ��ǰʮ���Ǹ�����
**/