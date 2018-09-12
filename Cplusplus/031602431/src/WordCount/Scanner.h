#define _CRT_SECURE_NO_WARNINGS 

#ifndef _SCANNER_
#define _SCANNER_


#include <string>
#include <map>
#include "ScanProcesser.h"

using namespace std;



// This class will open the file and convert every character to ScanProcesser
class Scanner{
public:
	Scanner():file(NULL),processer(NULL) {}
    Scanner(string inFilename, ScanProcesser* inProcesser);
	~Scanner() {
		if (file != nullptr) {
			fclose(file);
		}
	}
	int scan();


private:
	FILE* file;
	ScanProcesser* processer;

};

#endif