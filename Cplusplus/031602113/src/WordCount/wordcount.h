#pragma once

#include<fstream>  //ifstream
#include<iostream>
#include<string>     //°üº¬getline()
using namespace std;

class Wordcount
{
private:
	string Filename;
	int number;
public:
	void get_filename(string s);
	void word_count();
	void put_num();
};
