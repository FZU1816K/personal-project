#include "CountWords.h"

#define OUTWORD 0
#define P1 1
#define P2 2
#define P3 3
#define INWORD 4

int transition(int state, char input, int * count)
{
	switch (state)
	{
	case OUTWORD:
		if (!isalpha(input) || isspace(input)) return OUTWORD;
		else if (isalpha(input)) return P1;
		
	case P1:
		if (isalpha(input)) return P2;
		else return OUTWORD;

	case P2:
		if (isalpha(input)) return P3;
		else return OUTWORD;

	case P3:
		if (isalpha(input)) return INWORD;
		else return OUTWORD;

	case INWORD:
		if (isalnum(input)) return INWORD;
		else { (*count)++; return OUTWORD; }
	}
}

int CountWords(char * filename)
{
	int count = 0;
	char c;
	std::fstream file;
	file.open(filename, std::ios::in);
	int state = OUTWORD;
	while (file.get(c)) {
		state = transition(state, c, &count);
	}
	if (state == INWORD) {
		count++;
	}
	return count;
}
