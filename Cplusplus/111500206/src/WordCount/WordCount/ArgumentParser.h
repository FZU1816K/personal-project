#pragma once
#include <iostream>
#include <fstream>

/*
* Function name: Parse_Args
* Description:
*	Parse the argument given in the command line
* Parameter:
*	@argc: command line argument
*	@argv: command line argument
* Return:
*	@int: 0 if parse correctly, otherwise -1 and display information.
*/
int Parse_Args(int argc, char **argv);
