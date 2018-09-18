#pragma once
#ifndef CountWords_H
#define CountWords_H
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<algorithm>
#include<windows.h>
#include<map>
using namespace std;
int CountWords(char *file, map<string, int> &MapWord);
#endif