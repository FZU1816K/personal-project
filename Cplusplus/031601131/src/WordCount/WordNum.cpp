#include"WordNum.h"


int WordNum(char * filename)
{
	map<string, int> Word_Num_map;
	char ch;
	FILE *file;
	fopen_s(&file, filename, "rt");
	int flag = 0;			// state of DFA   in 0 1 2 3 4
	int count = 0;
	
	for (; (ch = fgetc(file)) != EOF;)
	{
		if ('A' <= ch && ch <= 'Z')
			ch = ch + 32;
		if (flag == 0) {
			if (ch >= 'a'&&ch <= 'z') { flag = 1;	}
		}
		else if (flag == 1) {
			if (ch >= 'a'&&ch <= 'z') { flag = 2;	 }
			else { flag = 0;  }
		}
		else if (flag == 2) {
			if (ch >= 'a'&&ch <= 'z') { flag = 3;	 }
			else { flag = 0;  }
		}
		else if (flag == 3) {
			if (ch >= 'a'&&ch <= 'z') { flag = 4;	 }
			else { flag = 0;  }
		}
		else if (flag == 4) {
			if (ch >= 'a'&&ch <= 'z' || (ch >= '0'&&ch <= '9')) { }
			else {
			
				flag = 0;
				count++;
			}
		}
	}
	if (flag == 4) {
		count++;
	}
	fclose(file);
	return count;
}