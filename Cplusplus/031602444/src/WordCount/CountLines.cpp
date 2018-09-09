#include"CountLines.h"

using namespace std;

int CountLines(char* filemm)//统计有效行数
{
	int lines = 0;
	char c;
	char lastline = '\0';
	
	ifstream f;

	f.open(filemm, ios::in);

	while (f.get(c))
	{
		
		if (lastline != '\n'&&c == '\n')
		{
			lines++;
		}
		if (lastline == '\n' && (c == '\t' || c == ' '))
		{
			lastline = '\n';
		}
		else
		{
			lastline = c;
		}
	}


	f.close();

	if ((c == '\t' || c == ' ') && (lastline == '\t' || lastline == ' '))
	{
		lastline = c;
	}
	//如果文本最后一个字符是换行符或者前一个字符是换行符当前字符是空格要减去一行
	else if (c == '\n' || (lastline = '\n' && (c == '\t' || c == ' ')))
	{
		lines--;
	}

	lines++;


	return lines;

}