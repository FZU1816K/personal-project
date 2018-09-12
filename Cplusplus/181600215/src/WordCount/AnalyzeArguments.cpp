#include "stdafx.h"
#include "AnalyzeArguments.h"

int AnalyseParameter(int argc, char **argv)
{
	if (argc != 2) {
		cout << "input error.\n";
		return -1;
	}
	ifstream fin(argv[1]);
	if (!fin) {
		cout << "can't open the file.\n";
		return -1;
	}
	
	return 1;
}