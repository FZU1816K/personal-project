#include "line_cnt.h"
#include "file.h"

int Line_counter::lines_counter(istream &f, Files &fn)
{
	int flag = 0;
	int cnt = 0;
	string temp = fn.get_alstring();
	int len = temp.length();
	for (int i = 0; i < len; i++)
	{
		if (temp[i] >= 33 && temp[i] <= 126)//表示该行是有效行
		{
			flag = 1;
			continue;
		}
		if (temp[i] == 10 && flag == 1)//当该行是有效行，并且遍历到1个换行符时，行数加1
		{
			cnt++;
			flag = 0;
		}
	}
	if (flag == 1)//最后一行如果没有换行符，也要加1
		cnt++;

	return cnt;
}