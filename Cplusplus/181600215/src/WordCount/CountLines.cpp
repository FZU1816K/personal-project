#include "stdafx.h"
#include "CountLines.h"

int CountLines(char *filename)
{
	ifstream file;
	file.open(filename);
	string str;
	int count = 0;
	regex rx("^\\s*$");//空行表达式
	while (getline(file, str)) {
		if (!regex_match(str, rx)) count++;
	}
	file.close();

	return count;
}