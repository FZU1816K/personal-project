#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include "pre.h"


class Files
{
private:
	char file_name[MAXLENGTH];
	string allwords;
public:
	Files()
	{
		file_name[0] = '\0';
		allwords = "";
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