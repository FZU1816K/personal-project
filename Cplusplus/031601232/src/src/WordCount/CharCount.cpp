#include "CharCount.h"
#include<fstream>
#include<iostream>

int CharCount(char * filename)
{
	int num = 0;
	char c;
	FILE *file;
	fopen_s(&file,filename, "rt");
	while (fgetc(file) != EOF) 
	{
		num++;
	}
	fclose(file);
	return num;

	
}