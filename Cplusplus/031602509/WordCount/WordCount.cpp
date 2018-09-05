#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace std;

#define MAX_LENGTH   100

struct file
{
	char file_path[MAX_LENGTH];
	char file_name[MAX_LENGTH];
	int count_chars;
	int count_words;
	int count_lines;
	file()
	{
		file_path[0] = '\0';
		file_name[0] = '\0';
		count_chars = 0;
		count_words = 0;
		count_lines = 1;
	}
}fnew;
int C_chars(istream &fl,string &a_str)
{
	char chr;
	int count_c = 0;
	while (!fl.eof())
	{
		fl.get(chr);
		if ((chr <= 126 && chr >= 32)||chr==9||chr==10)
		{
			if (fl.eof())
				break;
			a_str += chr;
			count_c++;
			if (chr == 10)
				fnew.count_lines++;
			//cout << chr <<" "<<count_c<< endl;
		}
	}
	return count_c;
}
int C_words(istream &fl)
{
	return 0;
}

int main(int argc,char *argv[])
{
	string all_str = "";
	int i;
	strcpy(fnew.file_name, argv[1]);
	cout << fnew.file_name<<endl;
	ifstream f;
	f.open(fnew.file_name, ios::in);
	if (!f.is_open())
	{
		cout << "can't open this file!";
	}
	fnew.count_chars = C_chars(f,all_str);
	cout << "chars = " << fnew.count_chars << "," << "lines = " << fnew.count_lines;
	//cout << all_str;
	system("pause");
	return 0;
}
