#include"CharacterCount.h"


int Character_Count(string filename)
{
	const char *k;
	k = filename.c_str();
	fstream f(k, ios::in);
	ofstream fout("result.txt", ios::app);
	if (!f) {
		fout << "Can't open file" << endl;

		return -1;
	}
	char c;
	int n = 0;
	while (f.get(c))n++;
	fout << "characters:" << n << endl;
	return n;

}