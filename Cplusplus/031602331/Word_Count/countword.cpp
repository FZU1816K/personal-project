#include "pch.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iterator>
#include<cctype>
#include<unordered_map>
#include "countword.h"
using namespace std;
int is_word(int state, char input, int * count)
{
	switch (state)
	{
	case Begin:
		if (isspace(input) || (!(input >= '0') && !(input <= '9'))) return Begin;

		if (isalpha(input)) return L2;
		if ((input >= '0'&&input <= '9')) return Wrong;

	case Wrong:

		if (isspace(input) || (!(input >= '0') && !(input <= '9'))) return Begin;
		else return Wrong;

	case L2:
		if ((input >= '0'&&input <= '9')) return Wrong;
		if (isalpha(input)) return L3;
		else return Begin;

	case L3:
		if ((input >= '0'&&input <= '9')) return Wrong;
		if (isalpha(input)) return L4;
		else return Begin;

	case L4:
		if ((input >= '0'&&input <= '9')) return Wrong;
		if (isalpha(input)) return Final;
		else return Begin;

	case Final:
		if (isalnum(input)) return Final;
		else { (*count)++; return Begin; }
	}
	return ERROR;
}

int count_word(char * filename)
{
	int count = 0;
	char c;
	std::fstream outfile;
	outfile.open(filename, std::ios::in);
	int state = Begin;
	while (outfile.get(c) && state != ERROR) {
		c = tolower(c);
		state = is_word(state, c, &count);
	}
	if (state == Final) {
		count++;
	}
	return count;
}