#include "pch.h"
#include <iostream>
#include <fstream>
#include "CountLine.h"
#include <string>

using namespace std;
int CountLine(char *filename)
{
	ifstream File;
	int cnt = 0;
	string tmp;
	File.open(filename);
	if (File.fail())
	{
		return 0;
	}
	else
	{
		while (getline(File, tmp))
		{
			bool is_empty = true;
			for (auto c : tmp)
			{
				if ((c != ' ')&& (c != '\n')&&(c !='	'))
				{
					is_empty = false;
				}
			}
			if (!is_empty)
			{
				cnt++;
			}
		}
		return cnt;
	}
}