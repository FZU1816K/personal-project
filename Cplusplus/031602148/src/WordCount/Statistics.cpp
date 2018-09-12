#include "stdafx.h"
#include "Statistics.h"
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
int Statistics::words(ifstream& in)//词频统计 
{
	string str;
	string temp;
	int flag = 0;
	int sum = 0;
	int star = 0;
	while (getline(in, str))//逐行读取
	{
		flag = 0;
		for (unsigned i = 0; i < str.length(); i++)//将大写字母转为小写字母 
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
		}
		for (unsigned j = 0; j < str.length(); j++)//提取合法单词并统计 
		{
			if (j == str.length()-1 && str[j] >= 'a'&&str[j] <= 'z'&&flag >= 3)//特殊处理
			{
				flag++;
				temp = str.substr(star, flag);//截取合法单词 
				if (word.count(temp))
				{
					word[temp]++;
				}
				else
				{
					word[temp] = 1;
					sum++;
				}
			}
			if (str[j] >= 'a'&&str[j] <= 'z')
			{
				if (flag == 0)
				{
					star = j;
				}
				flag++;
			}
			else
			{
				if (flag >= 4)
				{
					if (str[j] >= '0'&&str[j] <= '9')
					{
						if (j == str.length() - 1)
						{
							flag++;
						}
						else
						{
							flag++;
							continue;
						}
					}
					temp = str.substr(star, flag);//截取合法单词 
					if (word.count(temp))
					{
						word[temp]++;
					}
					else
					{
						word[temp] = 1;
						sum++;
					}
				}
				flag = 0;
			}
		}
	}
	in.clear();//指针重新定位至文件头部 
	in.seekg(0, ios::beg);
	return sum;
}
int Statistics::characters(ifstream& in)//统计字符数
{
	int num = 0;
	char ch;
	while (in.peek() != EOF)//按字符读取
	{
		in.get(ch);
		if (ch >= 0 && ch <= 255)
		{
			num++;
		}
	}
	in.clear();//指针重新定位至文件头部 
	in.seekg(0, ios::beg);
	return num;
}
int Statistics::lines(ifstream& in)	//统计有效行数
{
	int line = 0;
	string str;
	while (getline(in, str))
	{
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());//删除一行中的空格
		str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());//删除一行中的制表符
		if (str.length() > 0) //如果删除制表符和空格之后的一行数据还有其他字符就算有效行
		{

			line++;
		}
	}
	in.clear();//指针重新定位至文件头部 
	in.seekg(0, ios::beg);
	return line;
}
void Statistics::set(ifstream& in)//调用统计功能
{
	cnum = 0;
	lnum = 0;
	wnum = 0;
	cnum = characters(in);
	lnum = lines(in);
	wnum = words(in);
}
void Statistics::display(ofstream& out)//将结果输出至指定文档
{
	out << "characters: " << cnum << endl;
	out << "words: " << wnum << endl;
	out << "lines: " << lnum << endl;
	map<string, int>::iterator it;
	for (it = word.begin(); it != word.end(); it++)
	{
		int t = (*it).second;
		a.push_back(t);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < wnum && i <= 10; i++)
	{

		int t = a[i];
		for (it = word.begin(); it != word.end(); it++)
		{
			if ((*it).second == t)
			{
				out << "<" << (*it).first << ">: " << t << endl;
				(*it).second = 0;
				break;
			}
		}
	}
}
