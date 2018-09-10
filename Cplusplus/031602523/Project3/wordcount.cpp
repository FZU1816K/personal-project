#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <regex>
#include <algorithm>
#define MAXLENGTH   101


//https://blog.csdn.net/nichengwuxiao/article/details/78789225
//https://www.cnblogs.com/batman425/p/3179520.html
//https://www.cnblogs.com/hexiaobao/p/8134829.html

using namespace std;

struct files
{
	char file_path[MAXLENGTH];
	char file_name[MAXLENGTH];
	int chars_cnt;
	int words_cnt;
	int lines_cnt;
	files()
	{
		file_path[0] = '\0';
		file_name[0] = '\0';
		chars_cnt = 0;
		words_cnt = 0;
		lines_cnt = 1;
	}
};

struct words
{
	string allwords;
	int rank_cnt[11];
	string rank_name[11];
	words()
	{
		allwords = "";
		for (int i = 0; i < 11; i++)
		{
			rank_cnt[i] = 0;
			rank_name[i] = "";
		}
	}
};

int chars_counter(istream &f, files &fn, words &wn)
{
	char temp;
	int cnt = 0;
	while (!f.eof())
	{
		f.get(temp);
		if ((temp <= 126 && temp >= 32) || temp == 9 || temp == 10)
		{
			wn.allwords += temp;
			cnt++;
		}
	}

	return cnt;
}

int lines_counter(istream &f, files &fn, words &wn)
{
	int flag = 0;
	int cnt = 0;
	int len = wn.allwords.length();//文本长度
	for (int i = 0; i < len; i++)
	{
		if (wn.allwords[i] >= 33 && wn.allwords[i] <= 126)//表示该行是有效行
		{
			flag = 1;
			continue;
		}
		if (wn.allwords[i] == 10 && flag == 1)//当该行是有效行，并且遍历到1个换行符时，行数加1
		{
			cnt++;
			flag = 0;
		}
	}
	if (flag == 1)//最后一行如果没有换行符，也要加1
		cnt++;

	return cnt;
}





int words_counter(ifstream &f, files &fn, words &wn)
{
	int flag = 0;
	string temp = "";
	int len = wn.allwords.length();
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if ((wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122))//找到第一个字母  判断是不是单词
		{
			flag = 0;
			for (int j = i; j <= i + 3; j++)
			{
				if (wn.allwords[j] <= 64 || (wn.allwords[j] >= 91 && wn.allwords[j] <= 96) || wn.allwords[j] >= 123 || len - i < 4)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)//如果是单词就提取单词到temp
			{
				temp = "";
				for (; i < len && ((wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122) || (wn.allwords[i] >= 48 && wn.allwords[i] <= 57)); i++)
				{
					if (wn.allwords[i] >= 65 && wn.allwords[i] <= 90)
						wn.allwords[i] += 32;
					temp += wn.allwords[i];
				}
				cnt++;

				//cout << temp << endl;
			}
			else//如果不是单词就跳到下一个单词的第一个字母
			{
				for (; (wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122); i++) {}
			}
		}
		else if (wn.allwords[i] >= 48 && wn.allwords[i] <= 57)
		{
			for (; (wn.allwords[i] >= 65 && wn.allwords[i] <= 90) || (wn.allwords[i] >= 97 && wn.allwords[i] <= 122) || (wn.allwords[i] >= 48 && wn.allwords[i] <= 57); i++) {}
		}
	}

	return cnt;
}



int main(int argc, char *argv[])
{
	ifstream f;
	files file_input;
	words word;

	strcpy(file_input.file_name, argv[1]);
	cout << file_input.file_name << endl;

	f.open(file_input.file_name, ios::in);
	if (!f.is_open())
	{
		cout << "Warning! can't open this file!" << endl;
	}

	file_input.chars_cnt = chars_counter(f, file_input, word);
	file_input.lines_cnt = lines_counter(f, file_input, word);
	file_input.words_cnt = words_counter(f, file_input, word);

	
	cout << file_input.chars_cnt << endl;
	cout << file_input.lines_cnt << endl;
	cout << file_input.words_cnt << endl;

	system("pause");
	return 0;
}
