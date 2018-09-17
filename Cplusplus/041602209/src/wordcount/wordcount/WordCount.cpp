#include"WordCount.h"


int Word_Count(char *k)
{
	int sum = 0;
	int sign = 0;
	fstream fin(k, ios::in);
	ofstream fout("result.txt", ios::app);
	if (!fin) {
		fout << "Can't open file" << endl;

		return -1;
	}
	char character;

	int wordvalue = 0;
	string  temp;
	for (sign=0; (character = fin.get()) != EOF;sign++)
	{
		if ('A' <= character && character <= 'Z')
			character = character + 32;
		switch (wordvalue) {
		case 0: {
			if (character >= 'a'&&character <= 'z') {
				wordvalue = 1;
			}
			break;
		}
		case 1: {
			if (character >= 'a'&&character <= 'z') { wordvalue = 2; }
			else { wordvalue = 0; }
			break;
		}
		case 2: {
			if (character >= 'a'&&character <= 'z') { wordvalue = 3; }
			else { wordvalue = 0; }
			break;
		}
		case 3: {
			if (character >= 'a'&&character <= 'z') { wordvalue = 4; }
			else { wordvalue = 0; }
			break;
		}
		case 4: {
			if (character >= 'a'&&character <= 'z' || (character >= '0'&&character <= '9')) {}
			else {
				wordvalue = 0;
				sum++;
			}
			break;
		}
		}
	}

	if (wordvalue == 4) {
		sum++;
	}
	fout << "words:" << sum << endl;
	fin.close();
	return sum;
}