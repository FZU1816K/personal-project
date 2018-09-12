#include "CountChars.h"

int CountChars(char* file)
{
	int count = 0;
	string temp;
	ifstream inFile(file);
	while (getline(inFile, temp)) {
		for (int i = 0; i < (int)temp.length(); i++)
			if (isascii(temp[i]))	count++;
		count++;
	}
	if (count > 1)	count--;
	inFile.close();
	return count;
}