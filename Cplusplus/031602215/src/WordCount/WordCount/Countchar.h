#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int CountChar(char *filename)
{	//char *filename
	ifstream infile;
	
	if (filename == nullptr)
	{
		infile.open("input.txt");
	}
	else infile.open(filename);
	infile >> noskipws; //��ǿ�ƶ���ÿһ���ַ��������˿հ׷����������з���
	char c;
	int count = 0;
	while (!infile.eof())
	{
		infile >> c;  //�����ַ����
		if (c == 10 && c == ' '&&c == '\t') cout << "11111111111111111111" << endl;
		count++;
	}
	infile.close();
	return count-1;
}