// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include <fstream>
using namespace std;

typedef struct
{
	char s[60] = { 0 };
	int frq = 0;
}wd;

int n = 0;
wd temp, word[1000000];

int charcount(char *tx);
int linecount(char *tx);
int wordcount(char *tx);
void  sor(wd *f, int n);
void wordmax(char *tx);

// TODO: 在此处引用程序需要的其他头文件
