#include "pch.h"
#include "File.h"
#include "check.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char** argv)
{
	for (int i = 0; i < 10000; i++)
	{
		string input_fname = argv[1];
		string output_fname = argv[2];
		File my_file;
		my_file.file_output(input_fname, output_fname);
		//cout << "该程序已完成。" << endl;
	}
	return 0;
}