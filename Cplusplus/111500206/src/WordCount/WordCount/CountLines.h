#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#define EMPTY 0    // indicate a empty line
#define NONEMPTY 1 // indicate a non-empty line

/*
* Function name: CountLines
* Description: 
*	Count the number of lines of the file, skip empty lines.
* Parameter:
*	@filename: File that need to be counted
* Return:
*	@int: total number of lines
*/
int CountLines(char * filename);