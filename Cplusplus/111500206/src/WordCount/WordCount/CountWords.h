#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#define Separator(x) (isspace(x) || (!IsNum(x) && !isalpha(x))) 
#define IsNum(x) (x >= '0' && x <= '9')

#define OUTWORD 0 // 6 DFA states
#define P1 1
#define P2 2
#define P3 3
#define NotAWord 4 
#define VALIDWORD 5

#define ERROR 6

/*
* Function name: Transition
* Description: State transition process in DFA(Deterministic Finite Automaton) 
*			and add the counter of words.
* Parameter:
*	@state: current state
*	@input: current input
*	@count: counter of words
* Return:
*	@int: new state
*/
int Transition(int state, char input, int * count);
/*
* Function: CountWords
* Description: 
*	Count the total number of words. 'Word' starts with four consecutive 
*	letters, followed by letters and numbers
* Parameter:
*	@filename: File that need to be counted
* Return:
*	@int: total number of words
*/
int CountWords(char * filename);