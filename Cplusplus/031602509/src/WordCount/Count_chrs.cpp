#include "pch.h"
#include "work_2.h"
bool Letter_test(char &chr_test)
{
	return chr_test <= 'z' && chr_test >= 'a';	//字母判断
}

void reset_string(string &str)
{
	str = "";
}

bool Number_test(char &chr_test)
{
	return chr_test <= '9' && chr_test >= '0';	//数字判断
}


int C_chars(istream &fl, File &fn, Words &wn, vector <string> &str_lines)
{
	int count_chr = 0;
	string buffer_line;
	string lower_letter_str;
	char chr;					//单字符判断
	while (1){
		chr = fl.get();
		count_chr++;
		if (chr == '\n')
		{
			transform(buffer_line.begin(), buffer_line.end(), buffer_line.begin(), ::tolower);		//小写字母转换
			str_lines.push_back(buffer_line);					//回推新行
			reset_string(buffer_line);																//重置新行
		}
		buffer_line += chr;
		if (chr == EOF){
			count_chr -= 1;		//避免结尾字符
			if (buffer_line.size() > 0)
			{
				transform(buffer_line.begin(), buffer_line.end(), buffer_line.begin(), ::tolower);	//小写字母转换
				str_lines.push_back(buffer_line);				//回推新行
			}break;
		}
	}
	fn.count_chars = count_chr;
	return count_chr;
}