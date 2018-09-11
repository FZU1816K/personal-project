#pragma once
#include "pre.h"
#include "file.h"


class Line_counter
{
private:
	int lines_cnt;
public:
	Line_counter()
	{
		lines_cnt = 0;
	}
	int get_lnecnt()
	{
		return this->lines_cnt;
	}
	void set_lnecnt(int n)
	{
		this->lines_cnt = n; return;
	}
	int lines_counter(istream &f, Files &fn);
};