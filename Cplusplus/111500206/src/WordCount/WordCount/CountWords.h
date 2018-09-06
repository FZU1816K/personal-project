#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#define OUTWORD 0 // 5 DFA states
#define P1 1
#define P2 2
#define P3 3
#define INWORD 4
#define ERROR 5

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