#include "lower.h"
void lower(string& str) {//��дת����Сд
	for (int j = 0; j < str.size(); j++)
	{
		if (str[j] <= 'Z'&&str[j] >= 'A') {
			str[j] = str[j] + 32;
		}
	}
}