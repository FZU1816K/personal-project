#include "CharNum.h"
#include<fstream>
#include<iostream>

int CharNum(char * filename)
{
	int count = 0;
	char c;
	FILE *file;
	fopen_s(&file,filename, "rt");
	for (; fgetc(file) != EOF;) {
		count++;
	}
	fclose(file);
	return count;

	
}