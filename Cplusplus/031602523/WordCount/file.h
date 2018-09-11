#pragma once
#include "pre.h"


class Files
{
private:
	char file_name[MAXLENGTH];
	int chars_cnt;
	int words_cnt;
	int lines_cnt;
	string allwords;
public:
	Files()
	{
		file_name[0] = '\0';
		allwords = "";
		chars_cnt = 0;
		words_cnt = 0;
		lines_cnt = 1;
	}
	int get_chrcnt()
	{
		return this->chars_cnt;
	}
	void set_chrcnt(int n)
	{
		this->chars_cnt = n; return;
	}
	int get_wrdcnt()
	{
		return this->words_cnt;
	}
	void set_wrdcnt(int n)
	{
		this->words_cnt = n; return;
	}
	int get_lnecnt()
	{
		return this->lines_cnt;
	}
	void set_lnecnt(int n)
	{
		this->lines_cnt = n; return;
	}
	string get_alstring()
	{
		return this->allwords;
	}
	void set_alstring(string s)
	{
		this->allwords = s;
	}
	string get_filename()
	{
		return this->file_name;
	}
	void set_filename(char * s)
	{
		strcpy(this->file_name, s); return;
	}
};