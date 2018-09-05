#include "ArgumentParser.h"
#include <iostream>
int Parse_Args(int argc, char ** argv)
{
	// argv[1]是否存在
	if (argv[1] == NULL) {
		std::cout << "No input file name" << std::endl;
		return -1;
	}
		
	// 是否是一个文件名

	return 0;
}
