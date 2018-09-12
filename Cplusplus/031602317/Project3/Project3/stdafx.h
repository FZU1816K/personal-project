#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
struct Words
{
	char wordtype[1000];
	int frequency = 0;
	int lenth;
};
using namespace std;
void linecounter(char ch, int &lines);
void wordcounter(char ch, int &flag, int &words, char testword[]);
void charcounter(char ch, int &characters);
int min(int a, int b);