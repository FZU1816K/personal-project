#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
// DFA
int transition(int state, char input, int count);
// 统计单词的总数
int CountWords(char * filename);