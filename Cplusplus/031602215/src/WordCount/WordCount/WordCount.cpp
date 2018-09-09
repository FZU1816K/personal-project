#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include "Countchar.h"
#include"Countwords.h"
#include "Countwords_num.h"
#include "Countwords_words.h"
#include"Countlines.h"
using namespace std;


int main(int argc, char *argv[])
{
	ifstream infile;
	infile.open("input.txt");
	cout << "characters: "<<CountChar() << endl;
	cout << "words: " << Countwords_num(Countwords()) << endl;
	cout << "lines: " << Countlines() << endl;
	cout << Countwords_words(Countwords())<<endl;
	getchar();
	
	return 0;
}