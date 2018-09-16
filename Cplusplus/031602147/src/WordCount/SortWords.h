#pragma once
#ifndef SortWords_H
#define SortWords_H
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<algorithm>
#include<windows.h>
#include <utility>
#include<map>
using namespace std;
void SortWords(pair<string, int> top[], map<string, int> &MapWord, int words);
#endif