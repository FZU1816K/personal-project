#include "CountLines.h"

int CountLines(char * filename)
{
	int count = 0;
	char c;
	std::fstream file;
	file.open(filename);
	int state = EMPTY;
	while (file.get(c)) {
		if (state == EMPTY && !isspace(c)) {
			state = NONEMPTY;
		}
		if (c == '\n' && state == NONEMPTY) {
			count++;
			state = EMPTY;
		}
	}
	if (state == NONEMPTY) {
		count++;
	}
	return count;
}
