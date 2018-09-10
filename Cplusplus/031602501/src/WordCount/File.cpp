#include "pch.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include"File.h"
File::File(string infilepath, string outfilepath)		//构造函数初始化变量
{
	_infilepath = infilepath;
	ifs.open(_infilepath.c_str(), ios::in);
	if (!ifs)
		cout << "读取输入文件错误！" << endl;
	if (outfilepath != "")
	{
		_outfilepath = outfilepath;
		ofs.open(_outfilepath.c_str(), ios::out);
		if (!ofs)
			cout << "打开输出文件错误或输出文件正被占用！" << endl;
	}
}
//int File::geterror()
//{
//	return flag;
//}
string File::readfile()
{
	char a ;
	while (1)
	{
		a = ifs.get();
		if (a == EOF)break;
		content += a;
	}
	ifs.close();
	return content;
}
void File::DrawText(int characters, int words, int _lines, vector<vocabulary> _list)											//写入文件
{
	ofs << "characters: " << characters << endl;
	ofs << "words: " << words << endl;
	ofs << "lines: " << _lines << endl;
	for (int i = 0; i < _list.size(); i++)
		ofs << "<" << _list[i].word << ">" << ": " << _list[i].frequence[0] << endl;
}