#ifndef  _COUNTWORD_H_
#define _COUNTWORD_H_

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iterator>
#include<cctype>
#include<unordered_map>
#include "countchar.h"
#define Begin 0
#define Wrong 1
#define L2 2
#define L3 3
#define L4 4
#define Final 5
#define ERROR 6

using namespace std;
int is_word(int state, char input, int * count);


int count_word(char * filename);

#endif