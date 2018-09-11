#include "pch.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include"line_count.h"
using namespace std;

int Lines_Count(char *filename)
{
	int line_cnt = 0;
	string str;
	fstream f_tmp;
	f_tmp.open(filename);
	if (!f_tmp)
	{
		cout << "Can't open file :" << filename << "\nUsage:countch filename" << endl;
		exit(0);
	}
	while (getline(f_tmp, str, '\n'))
	{
		line_cnt++;
	}
	f_tmp.close();
//	cout << "lines:" << line_cnt << endl;
	return line_cnt;
}