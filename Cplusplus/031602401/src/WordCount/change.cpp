#include "change.h"
void change(string& str, char a[200]) {
	for (int j = 0; j < str.size(); j++)
	{
		a[j] = str[j];
	}
	a[str.size()] = '\0';
}