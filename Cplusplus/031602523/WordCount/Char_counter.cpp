#include "head.h"

int Char_counter::char_count(istream &f, Files &fn)
{
	char a;
	int cnt = 0;
	string temp = "";
	while (f.get(a))//字符读取不成功就终止
	{
		if ((a >= 32 && a <= 126) || a == '\n' || a == '\t')
			cnt++;
		temp += a;//把每个字符传入all_string
	}
	fn.set_alstring(temp);
	return cnt;
}
