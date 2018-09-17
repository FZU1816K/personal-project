#include "pch.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<algorithm>
#include"line_count.h"
using namespace std;

int Lines_Count(char *filename)
{
	int line_cnt = 0;
	int flag = 0;
	string str;
	char ch_tmp;
	fstream f_tmp;
	f_tmp.open(filename);
	if (!f_tmp)
	{
		cout << "Can't open file :" << filename << "\nUsage:countch filename" << endl;
		exit(0);
	}
	while (f_tmp.get(ch_tmp))
	{
		if (ch_tmp != ' ' && ch_tmp != '\t' && ch_tmp != '\n')
		{
			flag = 1;
		}
		else if (ch_tmp == '\n'&&flag == 1) {
			line_cnt++;
			flag = 0;
		}
	}
	if (flag == 1)line_cnt++;
	f_tmp.close();
//	cout << "lines:" << line_cnt << endl;
	return line_cnt;
}