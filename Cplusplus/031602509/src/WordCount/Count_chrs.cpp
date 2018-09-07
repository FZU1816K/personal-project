#include "work_2.h"
#include "stdafx.h"

int C_chars(istream &fl, File &fn, Words &wn)
{
	char chr;
	int count_c = 0, flag = 0;		//flag判断有效行
	while (!fl.eof())				//是否读到文件尾
	{
		fl.get(chr);
		if ((chr <= 126 && chr >= 32) || chr == 9 || chr == 10)
		{
			if (fl.eof())
				break;
			if (chr <= 126 && chr >= 33)
				flag = 1;
			wn.all_string += chr;	//完整字符串构建
			count_c++;
			if (chr == 10 && flag == 1)
			{
				fn.count_lines++;
				flag = 0;
			}
			//cout << chr <<" "<<count_c<< endl;
		}
	}
	if (flag == 1)
		fn.count_lines++;		//最末有效行不换行情况处理
	return count_c;
}