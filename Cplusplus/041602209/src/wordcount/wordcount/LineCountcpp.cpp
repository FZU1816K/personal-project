#include"LineCount.h"



int Line_Count(char *k)
{
	char c;
	fstream f(k, ios::in);
	ofstream fout("result.txt", ios::app);
	if (!f) {
		fout << "Can't open file" << endl;

		return -1;
	}
	int lineCnt = 0;

	bool line_value = false;
	while (f.get(c))
	{
		if (c > 32) line_value = true;

		if (c == '\n'&&line_value == true)
		{
			lineCnt++;
			line_value = false;
		}
	}
	if (line_value == true)lineCnt++;//����ͳ�� 
	fout << "lines:" << lineCnt << endl;
	f.close();
	return lineCnt;

}