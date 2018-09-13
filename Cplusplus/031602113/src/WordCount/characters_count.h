#ifndef CIRCLE_H
#define CIRCLE_H

#include<fstream>  //ifstream
#include<iostream>
#include<string>     //°üº¬getline()
using namespace std;
class Characters
{
private:
	string Filename;
	int number;
public:
	void get_filename(string s);
	void char_count();
	void put_num();

};

#endif
