#include "pch.h"
#include "CountChar.h"

int CountChar(char *filename)//ͳ���ַ��� 
{
	int sum = 0;
	ifstream file;
	file.open(filename);
	char ch;
	while ((ch = file.get()) != EOF)
	{
		sum++;
	}
	file.close();
	return sum;
}