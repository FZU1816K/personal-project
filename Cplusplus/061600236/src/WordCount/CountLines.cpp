#include "pch.h"
#include "CountLines.h"
using namespace std;

int CountLines(char *filename)//ͳ������ 
{
	ifstream file;
	file.open(filename);
	string s;
	int sum = 0;
	while (getline(file, s))
	{
		if (s != "\0")//������������ 
			sum++;
	}
	file.close();

	return sum;
}