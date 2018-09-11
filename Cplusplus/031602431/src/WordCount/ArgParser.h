#ifndef _ARG_PARSER_
#define _ARG_PARSER_

#include <iostream>
#include <string>
#include "Tools.h"

using namespace std;

class ArgParser{
public:
    ArgParser(int argc, char* argv[]);
	~ArgParser() {};
    string getFileName(){
        if (filename.empty())
            return "";
        else return filename;
    }

    int helpDoc();

private:
    string filename;

};

#endif