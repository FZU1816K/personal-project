#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<ctype.h>
#include<map>
using namespace std;
class Counter
{
private:int Line;
		int Ch;
		int Words;
		string Freq;
		string sfn, dfn;
public:Counter(){}
	   Counter(string sfn,string dfn)
	   {
		   this->sfn = sfn;
		   this->dfn = dfn;
		   Line = 0;
		   Ch = 0;
		   Words = 0;
		   Freq = "\0";
	   }
	   int LineCount();
	   int CharCount();
	   int WordCount();
	   string WordFreq();
	   void Write();
};

string Conventor(int src);