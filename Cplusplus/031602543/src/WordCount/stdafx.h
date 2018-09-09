#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<ctype.h>
#include<map>
using namespace std;
int LineCount(string fn);
int CharCount(string fn);
int WordCount(string fn);
string WordFreq(string fn);
void Write(string sfn, string dfn);
string Conventor(int src);