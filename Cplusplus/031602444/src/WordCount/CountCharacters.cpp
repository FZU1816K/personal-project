#include"CountCharacters.h"

using namespace std;

int CountCharacters(char* filemm)//ͳ���ַ���
{
	int characters = 0;
	char c;
	ifstream f;

	f.open(filemm, ios::in);

	while (f.get(c))
	{
		characters++;
	}

	f.close();

	return characters;
}