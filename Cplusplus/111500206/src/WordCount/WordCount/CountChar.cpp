#include "CountChar.h"

int CountChar(char * filename)
{
	std::fstream file;
	file.open(filename, std::ios::in);
	int count = 0;
	char c;
	while (file.get(c)) {
		count++;
	}
	file.close();
	return count;
}
