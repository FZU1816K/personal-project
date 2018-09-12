#include "tools.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int box_draw(std::string msg) {
	//draw a box for a message
	int spaces_no = 80 - (msg.length()) - 4;
	std::string spacer = " ";
	int i=0;
	while (i < spaces_no) {
		spacer += " ";
		i++;
	};

	std::cout<<"+---------------------------------------------------------------------------- - +"<<std::endl
		<< "| "<<msg<<spacer<<" |"<<std::endl
		<<"+---------------------------------------------------------------------------- - +" << std::endl;
	return 0;
}