#include"CountChar.h"
int  CountChar(string mInputFileName)
{
	ifstream ifs(mInputFileName);
	char charTemp;
	int sum = 0;
	while ((charTemp = ifs.get()) != EOF)
	{
		if (charTemp >= 0 && charTemp <= 255)
			sum++;
	}
	return sum;
}