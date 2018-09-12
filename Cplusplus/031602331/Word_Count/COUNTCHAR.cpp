
#include<pch.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iterator>
#include<cctype>
#include<unordered_map>
#include "countchar.h"

using namespace std;

bool is_char(char str)  // is_char 
{
	if (isalpha(str) || (str = 32) || (str = 9) || (str = 10))
		return true;
	else
		return false;
}

int count_charandline(fstream &outfile)  
{
	int char_num = 0;
	int line_num = 0;
	char str[100000];
	while (outfile.getline(str, 100000)) 
	{
		int tmp = 0;

		for (int i = 0; i < strlen(str); i++)
		{

			if (is_char(str[i]))  //tmp judge blank line
			{
				char_num++;
				tmp++;
			}
		}
		if (tmp != 0)
			line_num++;
		tmp = 0;
	
	}
	cout << "characters: " << char_num << endl << "line: " << line_num << endl;
	return 0;
}