#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include"problem.h"

map<string, int> _word;						//存储单词及单词出现的频率
vector<string>fqy;							//存储出现频率最高的十个单词
int fre[10] = { 0 };						//存储出现频率最高的十个单词的频率

int characters = 0;							//总字符数
int _lines = 0;								//总行数
int words = 0;								//总单词数

bool _ischar(char t)						//判断传入的字符是否为数字及字母（是则返回真）
{
	if (t<'0' || (t > '9'&&t < 'a') || t>'z')
		return false;
	else return true;
}
bool _nonumber(char t)						//判断传入的字符是否为字母（是则返回真）
{
	if (t >= 'a'&& t <= 'z')
		return true;
	else return false;
}

Problem::Problem(string infilepath, string outfilepath)		//构造函数初始化变量
{
	_infilepath = infilepath;
	_outfilepath = outfilepath;
	ifs.open(_infilepath.c_str(), ios::in);
	ofs.open(_outfilepath.c_str(), ios::out);
}

int Problem::classify(string lines)
{
	int flag = 0;
	string word;
	int _length = lines.length();
	characters += _length;
	for (int i = 0; i <= _length; i++)
	{
		lines[i] = tolower(lines[i]);			//同一变成小写字母
		if (lines[i] > ' ')flag = 1;			//判断是否为空字符
		if (_ischar(lines[i]) == false)
		{
			if (_nonumber(word[0]) == true && _nonumber(word[1]) == true && _nonumber(word[2]) == true && _nonumber(word[3]) == true)
				//判断前四位是否为字母（该单词是否为单词）
			{
				if (_word.find(word) == _word.end())//查找单词是否出现过
					_word[word] = 1;
				else _word[word]++;		//对应单词频率加一
			}
			word = "";
		}
		else word += lines[i];
	}
	return flag;
}
void Problem::get_line()
{
	if (!ifs)
		cout << "打开文件错误！" << endl;
	else
	{
		string line;
		while (1)
		{
			char a = ifs.get();
			if (a == EOF)break;//判断是否读到文件末尾
			line += a;
			if (a == '\n')
			{
				int flag = classify(line);
				if (flag != 0)
				{
					//if(printresult) cout << line << endl;
					_lines++;
				}
				line = "";
			}
		}
	}
	ifs.close();
}

//void Problem::display()
//{
//	for (auto my_Itr = _word.begin(); my_Itr != _word.end(); ++my_Itr) 
//	{
//		cout << my_Itr->first <<" "<< my_Itr->second<<endl;
//	}
//}

void Problem::_sort()
{
	for (int i = 0; i < 10; i++)
	{
		int max = 0;
		string word;
		for (auto my_Itr = _word.begin(); my_Itr != _word.end(); ++my_Itr)//遍历文本中出现的所有单词及其频率
		{
			if (my_Itr->second > max)
			{
				max = my_Itr->second;
				word = my_Itr->first;
			}
			if (i == 0)
				words += my_Itr->second;
		}
		_word[word] = -1;
		fqy.push_back(word);
		fre[i] = max;
		/*	cout << fqy[i] << ":" << max << endl;*/
	}
}

void Problem::result()
{

	//cout << "characters:" << characters << endl;
	//cout << "words: " << words << endl;
	//cout << "lines:" << _lines << endl;

	ofs << "characters: " << characters << endl;
	ofs << "words: " << words << endl;
	ofs << "lines: " << _lines << endl;
	for (int i = 0; i < 10; i++)
		ofs << "<" << fqy[i] << ">" << ": " << fre[i] << endl;
}