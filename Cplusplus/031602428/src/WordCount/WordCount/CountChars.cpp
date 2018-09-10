#include "CountChars.h"

int CountChars(char* file)
{
	int count = 0;
	string temp;
	ifstream inFile(file);
	while (getline(inFile, temp)) {
		count += temp.size() + 1;
	}
	count--;
	inFile.close();
	return count;
}