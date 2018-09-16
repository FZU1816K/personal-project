#include"fengzhuang.h"
void bigtosmall(string &x)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] >= 'A'&&x[i] <= 'Z')
		{
			x[i] = x[i] + 32;
		}
	}
}