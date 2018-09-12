#include "pch.h"
#include "Statistics.h"


inline int min(int a, int b)
{
	return a < b ? a : b;
}

Statistics::Statistics(vector<string> &file_lines)//构造，文件内容按vector<string>传入
	:m_file_lines(file_lines), m_char_num(0), m_word_num(0), m_line_num(0), calculated(false)
{

}

Statistics::~Statistics()//析构
{

}

bool Statistics::isLetter(const char &c)//判断给定字符是否为字母
{
	return c >= 'a' && c <= 'z';
}

bool Statistics::isNumber(const char &c)//判断给定字符是否为数字
{
	return c >= '0' && c <= '9';
}

void Statistics::calc()//统计功能，可不必手动调用
{
	for (unsigned int i = 0; i < m_file_lines.size(); i++)
	{
		const string &thisline = m_file_lines[i];
		m_char_num += int(thisline.size());

		bool is_a_line = false;
		for (unsigned int k = 0; k < thisline.size(); k++)//判断是否为空白行
		{
			if (thisline[k] > 32)//大于32为非空白字符
			{
				is_a_line = true;
				break;
			}
		}
		if (!is_a_line)
			continue;

		m_line_num++;
		unsigned int j = 0;
		while (j <= thisline.size() - 1)//统计单词个数
		{
			char c = thisline[j];
			if (isLetter(c))
			{
				string word;
				word.insert(word.end(), c);
				j++;
				if (j <= thisline.size() - 3)
				{
					while (j <= thisline.size() - 1 && (isLetter(thisline[j]) || isNumber(thisline[j])))
					{
						word.insert(word.end(), thisline[j]);
						j++;
					}
				}
				if (word.size() >= 4 && isLetter(word[0]) && isLetter(word[1]) && isLetter(word[2]) && isLetter(word[3]))
				{
					m_word_num++;
					if (m_wd_mp.find(word) == m_wd_mp.end())
						m_wd_mp[word] = 1;
					else
						m_wd_mp[word]++;
				}
			}
			else if (isNumber(c))
			{
				for (j++; j <= thisline.size() - 1 && (isLetter(thisline[j]) || isNumber(thisline[j])); j++);
			}
			else
			{
				j++;
			}
		}
	}
	calculated = true;

	/*for (auto it = m_wd_mp.begin(); it != m_wd_mp.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}*/
}

int Statistics::getCharNumber()//获取字符个数。若尚未进行统计，会自动调用calc()
{
	if (!calculated)
		calc();
	return m_char_num;
}

int Statistics::getWordNumber()//获取字符个数。若尚未进行统计，会自动调用calc()
{
	if (!calculated)
		calc();
	return m_word_num;
}

int Statistics::getLineNumber()//获取字符个数。若尚未进行统计，会自动调用calc()
{
	if (!calculated)
		calc();
	return m_line_num;
}

vector<map<string, int>::iterator> &Statistics::getTopWords(int top_num)//获取出现次数排名前几的单词
{
	if (!calculated)
		calc();
	top_num = min(int(m_wd_mp.size()), top_num);
	for (int i = 0; i < top_num; i++)
	{
		string maxstr;
		map<string, int>::iterator maxit = m_wd_mp.begin();
		for (map<string, int>::iterator it = m_wd_mp.begin(); it != m_wd_mp.end(); it++)
		{
			if (it->second > maxit->second)
			{
				maxit = it;
			}
		}
		m_top_words.push_back(maxit);
		maxit->second = -maxit->second;
	}
	for (unsigned int i = 0; i < m_top_words.size(); i++)
	{
		m_top_words[i]->second = -m_top_words[i]->second;
	}
	return m_top_words;
}

map<string, int> Statistics::_getAllWords()//获取整个字典的拷贝，仅用于调试。
{
	return m_wd_mp;
}