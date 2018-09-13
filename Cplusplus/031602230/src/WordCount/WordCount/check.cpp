#include "pch.h"
#include "check.h"
#include "CountAscii.h"
#include "CountFrequence.h"
#include "CountWords.h"
#include <iostream>
#include <string>
#include <fstream>
#include<algorithm>
using namespace std;
bool Check::check_isChar(char s1)
{
	if ((s1 >= 'a'&&s1 <= 'z') || (s1 >= 'A'&&s1 <= 'Z'))return true;
	else return false;
}
bool Check::check_isVal(char s1)
{
	if ((s1 >= 'a'&&s1 <= 'z') || (s1 >= 'A'&&s1 <= 'Z') || (s1 >= '0'&&s1 <= '9'))return true;
	else return false;
}
bool Check::check(string str)
{
	if (str.length() <= 3)return false;
	if (!(check_isChar(str[0]) && check_isChar(str[1]) && check_isChar(str[2]) && check_isChar(str[3])))return false;
	for (unsigned int i = 4; i < str.length(); i++)
	{
		if (!check_isVal(str[i]))return false;
	}
	return true;
}
void Check::testfile(string fname)
{
	Ascii asc;
	fstream file(fname);
	int count_ascii;
	count_ascii = asc.countAscii(fname);
	cout << count_ascii << endl;
}