#include "SwithToLower.h"

void co(char* outfile, int *cnt)
{
	fstream file(outfile);
	string str;
	while (getline(file, str))
	{

		for (int i = 0; i < str.size(); i++)
		{

			if (str[i] >= 'A'&& str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}

		}
		return;
	}
}