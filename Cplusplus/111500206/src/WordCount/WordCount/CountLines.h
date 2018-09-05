#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#define EMPTY 0
#define NONEMPTY 1
// 统计文件的有效行数，跳过空白行
int CountLines(char * filename);