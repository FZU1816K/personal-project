#include "CharNum.h"
#include<fstream>
#include<iostream>

int CharNum(char * filename)
{
	int count = 0;

	FILE *file;
	fopen_s(&file,filename, "rt");
	while (fgetc(file) != EOF) {
		count++;
	}
	fclose(file);
	return count;

	
}