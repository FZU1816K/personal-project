#include "pch.h"
#include "work_2.h"

int C_words(istream &fl, File &fn, Words &wn, Wordnode **l, vector <string> &str_lines)
{
	unsigned int i = 0, j = 0, k = 0;		//符合代码string.size()类型
	int count_lines = 0, count_words = 0;
	string temp_line = "", temp_word = "";
	char temp_chr;
	for (i = 0; i < str_lines.size(); i++)	//有效行数判断
	{
		temp_line = str_lines[i];
		int flag_line = 0;
		for (j = 0; j < temp_line.size(); j++)
		{
			if (temp_line[j] >= 33)
			{
				flag_line = 1; break;		//出现有效字符
			}
		}
		if (0 == flag_line)
		{
			continue;				//未出现有效字符	
		}
		count_lines++;
		k = 0;
		while (k < temp_line.size())	//单行单词判断
		{
			//cout<<temp_line.size();
			temp_chr = temp_line[k];
			if (temp_chr <= 57&&temp_chr >= 48)
			{
				k++;								//数字开头判断
				while (k <= temp_line.size() - 1 && ((temp_line[k] <= 57&&temp_line[k] >= 48) || (temp_line[k] <= 122&&temp_line[k] >= 97)))
					k++;
			}
			else if (temp_chr <= 122 && temp_chr >= 97)
			{
				temp_word = "";
				temp_word += temp_chr;		//字符补足
				//cout<<temp_word<<endl;
				k += 1;
				if (temp_line.size() - 2 > k)	//判断余下位数是否够装下一个单词
				{
					while (k < temp_line.size() && ((temp_line[k] <= 122 && temp_line[k] >= 97) || (temp_line[k] <= 57 && temp_line[k] >= 48)))
					{
						temp_word += temp_line[k];
						//cout << temp_word << endl;
						k += 1;
					}
				}
				if ((3 < temp_word.size() )&& (temp_word[0] <= 122&&temp_word[0] >= 97) && (temp_word[1] <= 122 &&temp_word[1] >= 97) && (temp_word[2] <= 122&&temp_word[2] >= 97) && (temp_word[3] <= 122&&temp_word[3] >= 97))
				{
					hash_insert(l, temp_word);	//判断是否4个字母开头
					count_words++;				//hash节点插入
				}
			}
			else
				k += 1;	//其他字符不计入单词
		}
	}
	fn.count_lines = count_lines;
	return count_words;

}