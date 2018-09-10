#include "stdafx.h"
using namespace std;
string Conventor(int src)//转换itos
{
	stringstream ss;
	string dst;
	ss.clear();
	ss << src;
	ss >> dst;
	return dst;
}
int Counter::LineCount()//统计行数
{
	ifstream infile;
	infile.open(sfn);
	string str[1000];
	int line = 0;
	while (infile)//文件处理 
	{
		getline(infile, str[line]);//按行读取
		if (str[line] != "\0")//统计行数，不计算空行
			line++;
	}
	//cout << "lines: " << line << endl;
	infile.close();
	return line;
}
int Counter::CharCount()
{
	ifstream infile;
	infile.open(sfn);
	string str[1000];
	int ch = 0, line = 0;

	while (infile)//文件处理 
	{
		getline(infile, str[line]);//按行读取
		line++;
	}
	for (int i = 0; i <= line; i++)
	{
		ch += str[i].size();
	}
	ch += line;
	//cout << "characters: " << ch << endl;
	infile.close();
	return ch;
}
int Counter::WordCount()
{
	ifstream infile;
	infile.open(sfn);
	string str[1000], str1[1000];
	int ch = 0, line = 0;
	int words = 0;

	while (infile)//文件处理 
		getline(infile, str[line++]);//按行读取
	line--;
	for (int i = 0; i<line; i++)//特殊符号处理
	{
		int j = 0;
		while (str[i][j] != '\0')
		{
			if (ispunct(str[i][j]))str[i][j] = ' ';//特殊符号处理为空格
			else
			{
				str[i][j] = tolower(str[i][j]);//化为小写
			}
			j++;
		}
	}
	int j = 0;

	for (int i = 0; i<line; i++)//将空格处理后的文档转化为单词 
	{
		istringstream stream(str[i]);
		while (stream)stream >> str1[j++];
	}
	//for (int k = 0; k < line; k++)cout << str1[k] << endl;

	j -= 1;
	words = 0;
	int k = 0;
	bool isword = true;
	for (int i = 0; i<j - 1; i++)//单词统计 
	{
		isword = true;
		for (k = 0; k<4; k++)//除去数字开头
		{
			if (str1[i][0] == '\0')
			{
				isword = false;
				break;
			}
			if (str1[i][k] == '\0')break;
			else if (!isalpha(str1[i][k])) {
				isword = false;
				break;
			}
		}
		if (isword) {
			words++;
		}
	}
	//for (int k = 0; k < line; k++)cout << str1[k] << endl;
	//cout << "words==" << words << endl;
	//for (int i = 0; i<j - 1; i++)
	//cout << str1[i] << endl;
	//cout << "words: " << words << endl;
	infile.close();
	return words;
}

string Counter::WordFreq()
{
	ifstream infile;
	infile.open(sfn);
	string str[1000], str1[1000], result;
	int ch = 0, line = 0;
	int words = 0;
	bool isword = true;
	while (infile)//文件处理 
		getline(infile, str[line++]);//按行读取
	line--;
	for (int i = 0; i<line; i++)//特殊符号处理
	{
		int j = 0;
		while (str[i][j] != '\0')
		{
			if (ispunct(str[i][j]))str[i][j] = ' ';//特殊符号处理为空格
			else
			{
				str[i][j] = tolower(str[i][j]);//化为小写
			}
			j++;
		}
	}

	int j = 0;

	for (int i = 0; i<line; i++)//将空格处理后的文档转化为单词 
	{
		istringstream stream(str[i]);
		while (stream)stream >> str1[j++];
	}
	//for (int k = 0; k < line; k++)cout << str1[k] << endl;
	j -= 1;
	words = 0;
	int k = 0;

	for (int i = 0; i<j - 1; i++)//单词筛选
	{
		isword = true;
		for (k = 0; k<4; k++)//除去数字开头
		{
			if (str1[i][0] == '\0')
			{
				isword = false;
				break;
			}
			if (str1[i][k] == '\0')break;
			else if (!isalpha(str1[i][k])) {
				isword = false;
				break;
			}
		}
		if (!isword) {
			str1[i] = '\0';
		}
	}

	map<string, int> mymap;
	map<string, int>::iterator it;


	for (int i = 0; i<j - 1; i++)
	{
		//查找 是否有key 有的话 value++
		//否则加入这个key 
		it = mymap.find(str1[i]);
		if (it == mymap.end())
		{
			mymap.insert(map<string, int> ::value_type(str1[i], 1));
		}
		else
		{
			mymap[str1[i]]++;
		}
	}
	it = mymap.begin();
	it++;
	//	for (; it != mymap.end(); it++)
	//	cout << '<'<<it->first << ">: " << it->second << endl;
	it = mymap.begin();
	it++;
	string temps = "\0";
	stringstream ss;
	int i = 0;
	for (i = 0; it != mymap.end(); it++, i++)
	{
		ss.clear();
		temps = "\0";
		str[i] = "\0";
		ss << it->second;
		ss >> temps;
		str[i] = "<" + it->first + "" + ">: " + temps;
	}

	//str[i] = "\0";
	//for (i = 0; str[i] != "\0"; i++)
	//	cout << str[i] << endl;
	for (i = 0; str[i] != "\0"; i++)
	{
		if(str[i][0]=='<')
			result += str[i] + "\n";
		else break;
	}
		infile.close();
	return result;
}
void Counter::Write()
{
	stringstream ss;
	ifstream infile;

	string result, temp;
	int v = 0;

	infile.open(sfn);
	result += "characters: " + Conventor(CharCount()) + "\n";
	result += "words: " + Conventor(WordCount()) + "\n";
	result += "lines: " + Conventor(LineCount()) + "\n";
	result += WordFreq();
	infile.close();

	ofstream outfile;
	outfile.open(dfn);
	outfile << result << endl;
	outfile.close();
}
int main(int argc, char* argv[])
{
	string sfn = argv[1];
	string dfn = "F:\\软工\\WordCount\\WordCount\\WordCount\\result.txt";
	Counter Cou(sfn, dfn);

	//Cou.CharCount();
	//Cou.WordCount();
	//Cou.LineCount();
	//Cou.WordFreq();
	//cout << Cou.WordFreq();
	Cou.Write();
	system("pause");
	return 0;
}