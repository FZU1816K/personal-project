#include<fstream>  //ifstream
#include<iostream>
#include<map>
#include<string>     
#include<algorithm>
#include <vector>
#include"characters_count.h"
#include"wordcount.h"
#include"frequency.h"
using namespace std;

int main(int argc, char *argv[]) //int argc, char *argv[]
{
	/* 参数的定义*/

	Characters c1;
	Wordcount c2;
	Frequency c3;
	map<string, int> all_words;
	pair<map<string, int>::iterator, bool> e_words;
	string word = "";
	ifstream infile;
	//string filename = "test.txt";
	string filename = argv[1];

	/**/

	/*心爱的接口们，贼累*/
	c1.get_filename(filename);
	c2.get_filename(filename);
	c3.get_filename(filename);
	c1.char_count();
	c2.word_count();
	c1.put_num();
	c2.put_num();
	c3.word_map();
	c3.put_map();
	/*  -///////////////-  */
	system("pause");
	return 0;
}
