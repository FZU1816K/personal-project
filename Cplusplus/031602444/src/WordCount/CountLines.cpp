#include"CountLines.h"

using namespace std;

int CountLines(char* filemm)//统计有效行数
{
	ifstream f;

	f.open(filemm, ios::in);
	
	int lines = 0;
	char c;
	int lineflag = 0;


	while (f.get(c))
	{

		if (c != ' ' && c != '\t' && c != '\n')
		{
			lineflag = 1;
		}
		else if (c == '\n'&&lineflag == 1) {
			lines++;
			lineflag = 0;
		}

	}
	f.close();

	if (lineflag == 1)lines++;
	

	return lines;

}


