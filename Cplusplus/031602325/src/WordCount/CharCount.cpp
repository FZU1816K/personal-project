#include"CharCount.h"

int CountChar(char * filename)
{
	int count = 0;
	char c;
	fstream file;
	file.open(filename, ios::in);
	while (file.get(c)) {
		count++;
	}
	file.close();
	return count;
}

