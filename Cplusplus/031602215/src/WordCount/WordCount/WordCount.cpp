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

	ofstream fout("output.txt"); //output.txt
	fout << "characters: "<<CountChar(argv[1]) << endl;   //no. of characters
	fout << "words: " << Countwords_num(Countwords(argv[1])) << endl;  //no. of words
	fout << "lines: " << Countlines(argv[1]) << endl;  //no. of lines
	vector<pair<string, int>> tVector;
	tVector =Countwords_words(Countwords(argv[1])); //words sorting
	 //getchar();
	for (int i = 0; i < tVector.size(); i++)
	{
		fout << tVector[i].first << ": " << tVector[i].second << endl;
		if (i == 9) break;
	}
	fout.close();
	
	return 0;
}