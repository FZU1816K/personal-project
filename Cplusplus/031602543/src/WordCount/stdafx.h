#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<ctype.h>
#include<algorithm>
#include<map>
#define Linethreshold 10000
#define Charthreshold 50000
#define Wordthreshold 10000
using namespace std;
struct WF
{
	int value;
	string key;
};
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
int DetectFileOpen(ifstream &infile);
int DetectOutfileOpen(ofstream &outfile);
string Conventor(int src);
