#include<iostream>
#include<string>
#include<map>
#include <fstream>
#include <algorithm>
#include<vector>
#include <assert.h>
using namespace std;

int character(char* path);//ͳ���ַ��� ���������
int word(char* path);//ͳ�Ƶ�����
int isstring(string c);//�ж��ַ����Ƿ����Ҫ��
string mytolower(string s);//�ַ���תСд
vector<pair<string, int>> WordsFrequency(char* path);//ͳ�ƴ�Ƶ�����
int cmp(const pair<string, int>& x, const pair<string, int>& y);//�Ƚ�
vector<string> splitt(const string &s);//�ָ����жϲ��и��ַ���
int main(int args, char* argv[]);//�������������
int line(char* path);//�������