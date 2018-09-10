#include "CountWords.h"

int Transition(int state, char input, int * count)
{
	switch (state)
	{
	case OUTWORD:
		if (Separator(input)) return OUTWORD; 
		if (isalpha(input)) return P1; 
		if (IsNum(input)) return NotAWord;

	case NotAWord:
		if (Separator(input)) return OUTWORD;
		else return NotAWord;

	case P1:
		if (IsNum(input)) return NotAWord;
		if (isalpha(input)) return P2;
		else return OUTWORD;

	case P2:
		if (IsNum(input)) return NotAWord;
		if (isalpha(input)) return P3;
		else return OUTWORD;

	case P3:
		if (IsNum(input)) return NotAWord;
		if (isalpha(input)) return VALIDWORD;
		else return OUTWORD;

	case VALIDWORD:
		if (isalnum(input)) return VALIDWORD;
		else { (*count)++; return OUTWORD; }
	}
	return ERROR;
}

int CountWords(char * filename)
{
	int count = 0;
	char c;
	std::fstream file;
	file.open(filename, std::ios::in);
	int state = OUTWORD;
	while (file.get(c) && state != ERROR) {
		c = tolower(c);
		state = Transition(state, c, &count);
	}
	if (state == ERROR) {
		std::cout << "DFA error state." << std::endl;
	}
	if (state == VALIDWORD) {
		count++;
	}
	return count;
}
