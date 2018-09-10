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

// return a orderd vector of WordNode
vector<WordNode> GetFirstTenWords(char* file_location);