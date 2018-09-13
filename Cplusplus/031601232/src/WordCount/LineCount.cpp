#include "LineCount.h"
int LineCount(char * filename)
{
	FILE *file;
	fopen_s(&file,filename, "rt");
	int num = 0;
	char c;
	int flag = 0;

	while((c = fgetc(file)) != EOF) 
	{
		if (!isspace(c))   
		{
			flag = 1;
		}
		if (flag && c == '\n') 
		{
			flag = 0;
			num++;
		}
	}
	if (flag == 1) 
	{
		num++;
	}
	fclose(file);
	return num;
}
