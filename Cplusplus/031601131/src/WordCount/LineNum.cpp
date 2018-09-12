#include "LineNum.h"
int LineNum(char * filename)
{
	FILE *file;
	fopen_s(&file,filename, "rt");
	int count = 0;
	char ch;
	int flag = 0;

	for (; (ch = fgetc(file)) != EOF;) {
		if (flag == 0 && !isspace(ch)) {
			flag = 1;
		}
		if (flag == 1 && ch == '\n') {
			count++;
			flag = 0;
		}
	}
	if (flag == 1) {
		count++;
	}
	fclose(file);
	return count;
}
