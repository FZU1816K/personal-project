#include<fstream>  //ifstream
#include<iostream>
#include<string>     //°üº¬getline()
#include"characters_count.h"

using namespace std;

void Characters::get_filename(string s)
{
	this->Filename = s;
}
void Characters::char_count()
{
	int count = 0;
	ifstream infile;
	char ch;
	infile.open(Filename);

	while (infile.get(ch))
	{
		count++;
	}
	this->number = count;
	infile.close();
}
void Characters::put_num()
{

	int i;
	i = this->number;
	cout << "×Ö·ûÊýÁ¿£º" << i << endl;
}