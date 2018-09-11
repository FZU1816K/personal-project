#include "argParser.h"
#include <fstream>
#include <cstdio>
#include <iostream>
#include "Tools.h"

using namespace std;


int argCheck(string filename) {
	// return 0 if the file can be opened, else return 1
	ifstream file(filename);
	if (!file) {
		perror("Argument error");
		return 1;
	}
	else{
		return 0;
	}
}

ArgParser::ArgParser(int argc, char* argv[]){
    if (argc != 2){
        perror("Too few or too many arguments");
        filename = string();
    }
    else{
        filename = string(argv[1]);
        ifstream inFile(filename);
        if (!(inFile)){
            perror("File error");
            filename = string();
        }
    }
}

int ArgParser::helpDoc(){
    box_draw("The WordCount Program Help");
    cout<<"./WordCount.exe filepath"<<endl;
	return 0;
}
