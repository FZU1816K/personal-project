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

int CountLine(char* file_location)
{
	ifstream instream;
	instream.open(file_location, ios::in);
	assert(instream.is_open());

	string line;
	int valid_lines = 0;
	while (getline(instream, line))
	{
		// statistics valid lines
		if (HaveVisibleChar(line)) valid_lines++;
	}

	instream.close();
	
	return valid_lines;
}