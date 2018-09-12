/**
 * Function:  CountLines
 * Description:  Count the number of lines of the file
 * Parameter:
   file:File that need to be counted
 * Return:
   int:the number of lines
 */
#include"CountLines.h"
int CountLines(char *file)
{
	int number = 0;//lines
	FILE *fp;
	char ch;
	errno_t err;
	if ((err = fopen_s(&fp, file, "r")) != 0)
	{
		printf("Can not open this file.\n");
		exit(0);
	}
	while (!feof(fp))
	{
		if ((ch = getc(fp)) != EOF)
		{
			if ((ch = getc(fp)) == '\n')
			{
				if (file[0] != '\0') number++;
			}
		}
	}
	fclose(fp);
	return number + 1;
}