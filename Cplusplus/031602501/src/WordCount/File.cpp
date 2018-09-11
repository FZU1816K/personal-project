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
	_outfilepath = outfilepath;
}
void File::OpenFile()
{
	ifs.open(_infilepath.c_str(), ios::in);
	if (!ifs)
		throw string("读取输入文件错误！");
	if (_outfilepath != "")
		ofs.open(_outfilepath.c_str(), ios::out);

}
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
	if (!ofs)
		throw string("打开输出文件错误或输出文件正被占用！");
	ofs << "characters: " << characters << endl;
	ofs << "words: " << words << endl;
	ofs << "lines: " << _lines << endl;
	for (int i = 0; i < _list.size(); i++)
		ofs << "<" << _list[i].word << ">" << ": " << _list[i].frequence[0] << endl;
}
string Parameters_judgment(int argc, char *argv[])			//主函数参数判断
{
	string filename = "";
	if (argc == 2)				//判断主函数参数是否为两个
		filename = argv[1];
	else if (argc == 1)
		cin >> filename;
	else throw string("输入参数过多，错误！");
	return filename;
}