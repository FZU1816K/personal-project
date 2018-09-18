/**
 * Function:  CountCharacters
 * Description:  Count the number of characters of the file
 * Parameter:
   file:File that need to be counted
 * Return:
   int:the number of characters
 */
#include"CountCharacters.h"
int CountCharacters(char *file)
{
	int number = 0;
	char ch;
	FILE *fp;
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
			if (0 <= ch && ch <= 255)number++;
		}
	}
	fclose(fp);
	return number;
}