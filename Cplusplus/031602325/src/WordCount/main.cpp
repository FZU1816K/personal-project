#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include"Preprocess.h"
#include"WordCount.h"
#include"CharCount.h"
#include"LineCount.h"

const int MAX_FILENAME = 266; //指定最大文件名长度

int main(int argc, char *argv[])
{
	char filename[MAX_FILENAME] ;
	ofstream result;
	result.open("result.txt");
	//scanf("%s", filename);
	strcpy_s(filename, argv[1]);
	Preprocess(filename);
	vector<pair<string, int>> word = CountWord();
	result << "charaters: " << CountChar(filename) << endl;
	result << "words: " << WordSum(word) << endl;
	result << "lines: " << CountLines(filename) << endl;
	int j = 0;
	for (auto i : word)
	{
		result << '<' << i.first << ">: " << i.second << endl;
		j++;
		if (j >= 10) 
		{
			break;
		}
	}
	return 0;
}
