#include "stdafx.h"

int main(int args,char* argv[])
{
	char* a = NULL;
	vector<pair<string, int>> tVector;
	//char* a = "input.txt";
	ofstream fout("result.txt");
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
	//输出统计字符数
	characters = character(a);
	fout << "characters: " << characters << endl;
	//输出统计单词数
	words = word(a);
	fout << "words: " << words << endl;
	int lines = line(a);
	fout << "lines: " << lines << endl;
	//输出统计前十词频
	tVector=WordsFrequency(a);
	for (int i = 0; i<tVector.size(); i++)
	{
		if (i == 10)
			break;
		fout << "<" << tVector[i].first << ">" << ": " << tVector[i].second << endl;
	}
	fout.close();
	return 0;
}