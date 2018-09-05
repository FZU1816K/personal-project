#include "ArgumentParser.h"
#include <iostream>
#include <fstream>
int Parse_Args(int argc, char ** argv)
{
	if (argv[1] == NULL) {
		std::cout << "No input file name" << std::endl;
		return -1;
	}
	
	std::fstream file;
	file.open(argv[1]);
	if (!file) {
		std::cout << "Failed to open file: " << argv[1] << std::endl;
		return -1;
	}
	return 0;
}
