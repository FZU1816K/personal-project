#include "Countlines.h"


bool isnum_str(char str)  //�ж��Ƿ����ַ�������
{
	if ((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9'))
		return true;
	else
		return false;
	
}

void count(fstream &outfile, int *cnt)  //ͳ�ƺ���
{
	char str[256];
	while (outfile.getline(str, 256))
	{
		int tmp = 0;
		for (int i = 0; i < (unsigned int)strlen(str); i++)
		{
			if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!' || str[i] == '\n')
				cnt[1]++;            //ͳ�Ƶ�����
			if (str[i] >= 'A'&& str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
			if (isnum_str(str[i]))
			{
				cnt[0]++;   tmp++;
			}    //ͳ���ַ�����tmp�ֲ��������������ǲ���һ�����С�
		}
		if (tmp != 0)
			cnt[2]++;                 //ͳ������
		tmp = 0;
	}
	return;
}