#include<iostream>
#include<string>
#include<map>
#include <fstream>
#include <algorithm>
#include<vector>
#include <assert.h>
using namespace std;

int character(char* path);//统计字符数 并输出行数
int word(char* path);//统计单词数
int isstring(string c);//判断字符串是否符合要求
string mytolower(string s);//字符串转小写
vector<pair<string, int>> WordsFrequency(char* path);//统计词频并输出
int cmp(const pair<string, int>& x, const pair<string, int>& y);//比较
vector<string> splitt(const string &s);//分隔符判断并切割字符串
int main(int args, char* argv[]);//输入输出主函数
int line(char* path);//输出行数