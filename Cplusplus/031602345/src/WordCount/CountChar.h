#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <String>
#include <fstream>
#include <assert.h>
#include "share.h"
using namespace std;

int CountChar(char* file_location)
{
	ifstream instream;

	// load file in binary mode to statistics characters(inclcude '\r' '\n')
	instream.open(file_location, ios::binary);
	assert(instream.is_open());

	char ch;
	int count_char = 0;
	while (instream.get(ch)) count_char += 1;
	
	instream.close();
	return count_char;
}