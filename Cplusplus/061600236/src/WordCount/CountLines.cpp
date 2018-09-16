#include "pch.h"
#include "CountLines.h"
using namespace std;

int CountLines(char *filename)//统计行数 
{
	ifstream file;
	file.open(filename);
	string s;
	int sum = 0;
	while (getline(file, s))
	{
		if (s != "\0")//遇到空行跳过 
			sum++;
	}
	file.close();

	return sum;
}