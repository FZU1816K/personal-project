#include"CountLines.h"

int CountLines(char *filename)
{
	ifstream File;
	int n = 0;
	char line[512];
	string temp;
	File.open(filename, ios::in);//ios::in ��ʾ��ֻ���ķ�ʽ��ȡ�ļ�
	if (File.fail())//�ļ���ʧ��:����0
	{
		return 0;
	}
	else//�ļ�����
	{
		while (getline(File, temp))
		{
			n++;
		}
		return n;
	}
	File.close();
}