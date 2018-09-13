#include "CountChar.h"
#include <iostream>
#include "pch.h"
#include <fstream>
using namespace std;
int CountChar(char *filename)
{
	fstream file(filename);
	int cnt = 0;
	char temp;
	while (file.get(temp))
	{
		cnt++;

	}
	return cnt;
}