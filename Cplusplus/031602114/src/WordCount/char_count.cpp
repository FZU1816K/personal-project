#include "pch.h"
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include"char_count.h"
using namespace std;

int Ch_Count(char *filename)						//�����ַ���Ŀ�������ո񣬻��з����Ʊ���ȵ�ascii����
{
	char ch_tmp;
	int ch_cnt = 0;
	fstream f_tmp;
	f_tmp.open(filename);
	if (!f_tmp)
	{
		cout << "Can't open file :" << filename << "\nUsage:countch filename" << endl;
		exit(0);
	}
	while (f_tmp.get(ch_tmp))
	{
		ch_cnt++;
	}
//	cout << "characters:" << ch_cnt << endl;
	f_tmp.close();
	return ch_cnt;
}