#include "pch.h"
#include "work_2.h"

int C_words(istream &fl, File &fn, Words &wn, Wordnode **l, vector <string> &str_lines)
{
	unsigned int i = 0, j = 0, k = 0;		//���ϴ���string.size()����
	int count_lines = 0, count_words = 0;
	string temp_line = "", temp_word = "";
	char temp_chr;
	for (i = 0; i < str_lines.size(); i++)	//��Ч�����ж�
	{
		temp_line = str_lines[i];
		int flag_line = 0;
		for (j = 0; j < temp_line.size(); j++)
		{
			if (temp_line[j] >= 33)
			{
				flag_line = 1; break;		//������Ч�ַ�
			}
		}
		if (0 == flag_line)
		{
			continue;				//δ������Ч�ַ�	
		}
		count_lines++;
		k = 0;
		while (k < temp_line.size())	//���е����ж�
		{
			//cout<<temp_line.size();
			temp_chr = temp_line[k];
			if (temp_chr <= '9'&&temp_chr >= '0')
			{
				k++;								//���ֿ�ͷ�ж�
				while (k <= temp_line.size() - 1 && ((temp_line[k] <= '9'&&temp_line[k] >= '0') || (temp_line[k] <= 'z'&&temp_line[k] >= 'a')))
					k++;
			}
			else if (temp_chr <= 'z' && temp_chr >= 'a')
			{
				temp_word = "";
				temp_word += temp_chr;		//�ַ�����
				//cout<<temp_word<<endl;
				k += 1;
				if (temp_line.size() - 2 > k)	//�ж�����λ���Ƿ�װ��һ������
				{
					while (k < temp_line.size() && ((temp_line[k] <= 'z' && temp_line[k] >= 'a') || (temp_line[k] <= '9' && temp_line[k] >= '0')))
					{
						temp_word += temp_line[k];
						//cout << temp_word << endl;
						k += 1;
					}
				}
				if (3 < temp_word.size() && (temp_word[0] <= 'z'&&temp_word[0] >= 'a') && (temp_word[1] <= 'z'&&temp_word[1] >= 'a') && (temp_word[2] <= 'z'&&temp_word[2] >= 'a') && (temp_word[3] <= 'z'&&temp_word[3] >= 'a'))
				{
					hash_insert(l, temp_word);	//�ж��Ƿ�4����ĸ��ͷ
					count_words++;
				}
			}
			else
				k += 1;	//�����ַ������뵥��
		}
	}
	fn.count_lines = count_lines;
	return count_words;

}