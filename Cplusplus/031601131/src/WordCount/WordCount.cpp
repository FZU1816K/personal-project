// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include <iostream>
#include <fstream>
#include "CharNum.h"
#include "LineNum.h"
#include"WordNum.h"
#include "Word_Fre.h"
using namespace std;


int main(int argc, char *argv[])
{
	

	int Char_Number = CharNum(argv[1]);
	int Lines_Number = LineNum(argv[1]);
	int Words_Number = WordNum(argv[1]);

	printf("In this file:\n");
	printf("Number of characters : %d\n", Char_Number);
	printf("Number of non-empty lines: %d\n", Lines_Number);
	printf("Number of words: : %d\n", Words_Number);

	Word_Fre(argv[1]);			//Word frequency statistics

	
	return 0;
}
