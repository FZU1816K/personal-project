#include "pch.h"
#include "work_2.h"
bool Letter_test(char &chr_test)
{
	return chr_test <= 'z' && chr_test >= 'a';	//��ĸ�ж�
}

void reset_string(string &str)
{
	str = "";
}

bool Number_test(char &chr_test)
{
	return chr_test <= '9' && chr_test >= '0';	//�����ж�
}


int C_chars(istream &fl, File &fn, Words &wn, vector <string> &str_lines)
{
	int count_chr = 0;
	string buffer_line;
	string lower_letter_str;
	char chr;					//���ַ��ж�
	while (1){
		chr = fl.get();
		count_chr++;
		if (chr == '\n')
		{
			transform(buffer_line.begin(), buffer_line.end(), buffer_line.begin(), ::tolower);		//Сд��ĸת��
			str_lines.push_back(buffer_line);					//��������
			reset_string(buffer_line);																//��������
		}
		buffer_line += chr;
		if (chr == EOF){
			count_chr -= 1;		//�����β�ַ�
			if (buffer_line.size() > 0)
			{
				transform(buffer_line.begin(), buffer_line.end(), buffer_line.begin(), ::tolower);	//Сд��ĸת��
				str_lines.push_back(buffer_line);				//��������
			}break;
		}
	}
	fn.count_chars = count_chr;
	return count_chr;
}