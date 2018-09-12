#pragma once
#include<iostream>
#include <fstream>
using namespace std;

typedef struct
{
	char s[30] = { 0 };
	int frq = 0;
}wd;

int wordcount(char *tx);