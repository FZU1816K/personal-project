#pragma once
#include "pre.h"
#include "file.h"

class Char_counter
{
private:
	int chars_cnt;
public:
	Char_counter()
	{
		chars_cnt = 0;
	}
	int char_count(istream &f, Files &fn);
	int get_chrcnt()
	{
		return this->chars_cnt;
	}
	void set_chrcnt(int n)
	{
		this->chars_cnt = n; return;
	}
};