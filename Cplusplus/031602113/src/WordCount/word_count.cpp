#include<fstream>  //ifstream
#include<iostream>
#include<map>
#include<string>     //����getline()
#include<cmath>
#include"wordcount.h"
using namespace std;

void Wordcount::get_filename(string s)
{
	this->Filename = s;
}
void Wordcount::word_count()
{
	string word = "";
	int ch_count = 0;//���ʳ���
	int w_count = 0;//������Ŀ
	ifstream infile;
	char c;
	infile.open(Filename);

	while (infile.get(c))//����
	{
		if ('A' <= c && c <= 'Z')//�Ѵ�д����Сд
		{
			c = c + 32;
		}
		if (ch_count < 4)//�жϵ��ʳ����Ƿ����4
		{
			if (c >= 'a'&&c <= 'z')
			{
				word = word + c;
				ch_count++;
			}
			else
			{
				ch_count = 0;//���ʳ��ȳ�ʼ��
				word = "";//���ʳ�ʼ��
				continue;
			}
		}
		else
		{
			if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9'))
			{
				word = word + c;
				while (infile.eof()) {

					w_count++;
				}


				continue;
			}
			else {

				w_count++;
				ch_count = 0;
				word = "";

			}
		}
	}
	if (infile.eof())
	{
		if (ch_count >= 4)
			w_count++;
	}
	this->number = w_count;
	infile.close();
}
void Wordcount::put_num()
{

	int i;
	i = this->number;
	cout << "����������" << i << endl;
}