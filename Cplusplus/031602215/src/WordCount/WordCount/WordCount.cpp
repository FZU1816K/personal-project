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

	cout << "characters: "<<CountChar(argv[1]) << endl;   
	cout << "words: " << Countwords_num(Countwords(argv[1])) << endl;
	cout << "lines: " << Countlines(argv[1]) << endl;
	Countwords_words(Countwords(argv[1]));
	getchar();
	
	return 0;
}