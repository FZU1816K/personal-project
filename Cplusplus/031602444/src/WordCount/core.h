#pragma once
#ifndef _CORE_H
#define _CORE_H    
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

void CountCharacters(ifstream& filemm);//统计行数和字符数
void CountWord(ifstream& filemm, map<string, int>& mapp);//统计词数词频
void SortWord(map<string, int>& mapp);//词频排序

#endif