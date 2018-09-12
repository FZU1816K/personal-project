#include<stdio.h>
#include<cstdlib>
#include"Preprocess.h"
#include"WordCount.h"
#include"CharCount.h"
#include"LineCount.h"

const int FREQUENCY_COUNT = 6;	//用户指定统计词的频数
const int MAX_FILENAME = 266; //指定最大文件名长度

int main()
{
	char filename[MAX_FILENAME] ;
	scanf("%s", filename);
	Preprocess(filename);
	printf("charaters:%d\n", CountChar(filename));
	printf("lines:%d\n", CountLines(filename));
	countWord();
	system("PAUSE");
	return 0;
}
