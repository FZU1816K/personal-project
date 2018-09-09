#include "pch.h"
#include "myIO.h"


string myIO::GetFileNameFromArgs(int argc, char *argv[]) // 用于从命令行传入的参数中提取出输入文件名
{
	if (argc == 1)//直接运行
	{
		return "input.txt";
	}
	else if (argc == 2)//通过命令行传参打开
	{
		return argv[1];
	}
	else
	{
		throw "参数过多，错误";
	}
}

bool myIO::ReadFileLines(string file_name, vector<string> &file_lines) //给定文件名，以vector<string>形式返回文件内容，每个元素代表一行
{
	ifstream ifs(file_name);
	if (!ifs)
	{
		throw "读取文件时打开文件异常";
		return false;
	}
	else
	{
		string line_buf, str_low;
		char c;
		int _cnum = 0;
		while (true)//读取文件，按字符读入，拼装成行，存于file_lines中
		{
			c = ifs.get();
			if (c == EOF)
			{
				if (line_buf.size() > 0)
				{
					str_low.resize(line_buf.size());
					transform(line_buf.begin(), line_buf.end(), str_low.begin(), tolower);
					file_lines.push_back(str_low);
					//cout << str_low;
				}
				break;
			}
			line_buf += c;
			_cnum++;
			if (c == '\n')
			{
				str_low.resize(line_buf.size());
				transform(line_buf.begin(), line_buf.end(), str_low.begin(), tolower);
				file_lines.push_back(str_low);
				//cout << str_low;
				line_buf = "";
			}
		}
		//cout << "std char num:" << _cnum << endl;
		ifs.close();
		return true;
	}
}

bool myIO::Output(int char_num, int word_num, int line_num, vector<map<string, int>::iterator> &top10wd,
	bool toConsole, bool toFile, string file_name)// 结果输出。通过toConsole、toFile设置从控制台、文件输出。
{
	if (toConsole)// output to console
	{
		cout << "characters: " << char_num << endl;
		cout << "words: " << word_num << endl;
		cout << "lines: " << line_num << endl;
		for (unsigned int i = 0; i < top10wd.size(); i++)
		{
			cout << "<" << top10wd[i]->first << ">: " << top10wd[i]->second << endl;
		}
	}
	if (toFile)// output to file
	{
		ofstream ofs(file_name);
		if (!ofs)
		{
			throw "输出文件时打开文件异常";
			return false;
		}
		else
		{
			ofs << "characters: " << char_num << endl;
			ofs << "words: " << word_num << endl;
			ofs << "lines: " << line_num << endl;
			for (unsigned int i = 0; i < top10wd.size(); i++)
			{
				ofs << "<" << top10wd[i]->first << ">: " << top10wd[i]->second << endl;
			}
			ofs.close();
		}
	}
	return true;
}
