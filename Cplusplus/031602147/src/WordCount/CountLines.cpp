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
	ifstream infile(file);
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	string str;
	int number = 0;//lines
	while(getline(infile, str))
	{
		remove(str.begin(), str.end(), ' ');/*delete spaces in a row*/
		remove(str.begin(), str.end(), '\t');/*delete tab in a row*/
		/*Statistically valid rows*/
		if (str.length() > 0)
		{
			number++;
		}
	}
	return number;
}