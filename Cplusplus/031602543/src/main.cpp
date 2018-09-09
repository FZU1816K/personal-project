#include "header.h"
using namespace std;
int main()
{
	string sfn = "test.txt";
	string dfn = "result.txt";

	 CharCount(sfn);
	 WordCount(sfn); 
	 LineCount(sfn);
	WordFreq(sfn);
	Write(sfn,dfn);
	system("pause");
	return 0;
}