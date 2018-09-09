#include<iostream>
#include<fstream>
#include<string>
#include"CountChar.h"
#include"CountLines.h"
using namespace std;
int main(int argc,char **argv)
{
	int temp=initialization(argc,argv);
	if(temp==-1) {                               //说明cmd窗口输入错误。 
		cout<<"Sorry, something errors happened!"<<endl;
		return 0;
	}
	//进行文件分析计算。 
	int chars_cnt=CountChar(argv[1]);
	int words_cnt=CountWords(argv[1]);
	int lines_cnt=CountLines(argv[1]);
	??? top10=WordsTop10(argv[1]);
	//
	//输出结果。
	cout<<"characters:"<<chars_cnt<<endl;
	cout<<"words:"<<words_cnt<<endl;
	cout<<"lines:"<<lines_cnt<<endl;
	
	return 0; 
	
}
