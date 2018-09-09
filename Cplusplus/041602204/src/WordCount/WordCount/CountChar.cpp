#include"CountChar.h"
int CountChar(char * filename)
{
	int cnt = 0;
	char c;
	std::fstream file;
	file.open(filename, std::ios::in);
	while (file.get(c)) {
		cnt++;
	}
	file.close();
	return cnt;
}
