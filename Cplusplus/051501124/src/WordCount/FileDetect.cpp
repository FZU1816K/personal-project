#include "pch.h"
#include "FileDetect.h"

using namespace std;

int FileValidTest(char **argv)
{
	if (argv[1] == NULL)
	{
		cout << "no input file" << endl;
		return 1;
	}
	else if (argv[2] != NULL)
	{
		cout << "too many arguments" << endl;
		return 2;
	}
	string filename = argv[1];
	ifstream input;
	input.open(filename);
	if (input.fail())
	{
		cout << "the file is't exist" << endl;
		return 3;
	}
	
	input.close();
	return 0;
}