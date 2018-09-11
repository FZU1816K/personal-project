#include "stdafx.h"

int main(int args,char* argv[])

{
	char* a = NULL;
	//char* a = "input.txt";
	
	a = argv[1];
	if (argv[1] == NULL)
	{
		cout << "没有输入文本路径！" << endl;
		return 1;
	}
	else if (argv[2] != NULL)
	{
		cout << "输入参数过多！" << endl;
		return 2;
	}
	string filename = argv[1];
	ifstream input;
	input.open(filename);
	if (input.fail())
	{
		cout << "文件不存在！" << endl;
		return 3;
	}
	input.close();
	
	int characters,words;
	//统计字符数
	ofstream fout("characters.txt");
	characters = character(a);
	fout << "characters: " << characters << endl;
	fout.close();
	//统计单词数
	ofstream foutt("words.txt");
	words = word(a);
	foutt << "words: " << words << endl;
	foutt.close();
	//统计前十词频
	WordsFrequency(a);
	return 0;
}