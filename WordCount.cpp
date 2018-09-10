#include "stdafx.h"


using namespace std;

int main(int argc, char *argv[])
{
	for (int i = 0; i<argc; i++)
		cout << argv[i] << endl;
	const char* filename;
	if(argv[1]==NULL)
		filename = "input.txt";
	else
		filename = argv[1];
	
	FILE *fp;
	fopen_s(&fp, filename, "r");
	WordCount A(fp,filename);
	cout<<"characters:"<<A.CharCount()<<endl;
	cout << "words:" << A.WordNum() << endl;
	cout << "lines:"<< A.LineCount() << endl;
	A.LetterCount();
	fclose(fp);
	system("pause");
	return 0;
}