#include"CountLines.h"

int CountLines(char *filename)
{
	ifstream File;
	int n = 0;
	char line[512];
	string temp;
	File.open(filename, ios::in);//ios::in 表示以只读的方式读取文件
	if (File.fail())//文件打开失败:返回0
	{
		return 0;
	}
	else//文件存在
	{
		while (getline(File, temp))
		{
			n++;
		}
		return n;
	}
	File.close();
}