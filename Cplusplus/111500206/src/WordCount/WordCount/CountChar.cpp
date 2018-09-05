#include "CountChar.h"

int CountChar(char * filename)
{
	int count = 0;
	char c;
	std::fstream file;
	file.open(filename, std::ios::in);
	while (file.get(c)) {
		count++;
	}
	file.close();
	return count;
}
