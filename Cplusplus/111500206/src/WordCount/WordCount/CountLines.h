#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#define EMPTY 0    // indicate a empty line
#define NONEMPTY 1 // indicate a non-empty line
// 统计文件的有效行数，跳过空白行
int CountLines(char * filename);