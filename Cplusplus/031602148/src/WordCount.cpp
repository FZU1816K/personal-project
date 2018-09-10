#include "stdafx.h"

using namespace std;

class Statistics
{
public :
	int cnum;//字符数
	int wnum;//单词数
	int lnum;//行数
	vector<int>a;//排序用
	map<string, int> word;//记录单词及词频
	void set(ifstream& in);//统计
	void output(ofstream& out);//输出
	int characters(ifstream& in);//统计字符数
	int	words(ifstream& in);//统计单词数
	int lines(ifstream& in);//统计行数
};

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
	while (getline(in, str))
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
					//cout<<"temp:"<<temp<<endl;
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
	while (in.peek() != EOF)
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
	cnum = characters(in);
	lnum = lines(in);
	wnum = words(in);
}
void Statistics::output(ofstream& out)//将结果输出至指定文档
{
	out << "characters: " << cnum << endl;
	out << "words: " << wnum << endl;
	out << "lines: " << lnum << endl;
	map<string, int>::iterator it;
	for (it = word.begin(); it != word.end(); it++)
	{
		int m = (*it).second;
		a.push_back(m);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < wnum; i++)
	{
		int m = a[i];
		for (it = word.begin(); it != word.end(); it++)
		{
			if ((*it).second == m)
			{
				out << "<" << (*it).first << "> :" << m << endl;
				(*it).second = 0;
				break;
			}
		}
	}
}
int main(int argc, char *argv[])
{
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1], ios::in);
	if (infile.fail())
	{
		cout << "Open readfile failed!" << endl;
		exit(1);
	}
	outfile.open("result.txt", ios::out);
	if (outfile.fail())
	{
		cout << "Open writefile failed!" << endl;
		exit(1);
	}
	Statistics	s;
	s.set(infile);
	s.output(outfile);
	infile.close();
	outfile.close();
	system("pause");
	return 0;
}