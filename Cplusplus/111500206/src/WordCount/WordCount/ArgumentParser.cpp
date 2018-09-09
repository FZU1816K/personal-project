#include "ArgumentParser.h"

int Parse_Args(int argc, char ** argv)
{
	if (argv[1] == NULL) {
		printf("No input file name!\n");
		return -1;
	}

	if (argv[2] != NULL) {
		printf("Input too many argument!\n");
	}
	
	std::fstream file;
	file.open(argv[1]);
	if (!file) {
		printf("Failed to open file: %s\n", argv[1]);
		return -1;
	}
	file.close();
	return 0;
}
