#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include"Preprocess.h"
#include"WordCount.h"
#include"CharCount.h"
#include"LineCount.h"

const int FREQUENCY_COUNT = 6;	//用户指定统计词的频数
const int MAX_FILENAME = 266; //指定最大文件名长度

int main(int argc, char *argv[])
{
	char filename[MAX_FILENAME] ;
	//scanf("%s", filename);
	strcpy_s(filename, argv[1]);
	Preprocess(filename);
	vector<pair<string, int>> word = CountWord();
	printf("charaters:%d\n", CountChar(filename));
	PrintSum(word);
	printf("lines:%d\n", CountLines(filename));
	PrintWord(word);
	return 0;
}
