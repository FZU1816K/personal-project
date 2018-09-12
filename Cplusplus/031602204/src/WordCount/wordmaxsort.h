#pragma once
#include<iostream>
#include <fstream>
using namespace std;

typedef struct
{
	char s[30] = { 0 };
	int frq = 0;
}wd1;

void  sor(wd1 *f, int n);
void wordmax(char *tx);