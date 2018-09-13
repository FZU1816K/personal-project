#include "lower.h"
void lower(string& str) {//大写转化成小写
	for (int j = 0; j < str.size(); j++)
	{
		if (str[j] <= 'Z'&&str[j] >= 'A') {
			str[j] = str[j] + 32;
		}
	}
}