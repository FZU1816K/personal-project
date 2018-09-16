#include "FileIO.h"

//逐个字符读取文件
bool FileIO::readChar(int argc, char *argv[],string &charBuf,vector<string> &linesBuf)
{
	string filename = FileIO::getFileName(argc, argv);
	ifstream rf(filename);
	if (!rf) {
		return false;
	}
	else
	{
		string tempLine;
		char c;
		while (1)
		{
			c = rf.get();
			if (c == EOF)	//文件末尾
			{
				if (tempLine.size() > 0)
				{
					transform(tempLine.begin(), tempLine.end(), tempLine.begin(), ::tolower);
					linesBuf.push_back(tempLine);
				}
				break;
			}
			charBuf += c;
			tempLine += c;
			if (c == '\n')
			{
				transform(tempLine.begin(), tempLine.end(), tempLine.begin(), ::tolower);
				linesBuf.push_back(tempLine);
				tempLine = "";
			}
		}
		rf.close();
		return true;
	}
}
//输出文件
void FileIO::outputToFile(int characterCount, int wordCount,int lineCount, vector<map<string,int>::iterator> &top10Word)
{
	ofstream wf("result.txt", ios::out);
	wf << "characters: " << characterCount << endl;
	wf << "words: " << wordCount << endl;
	wf << "lines: " << lineCount << endl;
	for (int i = 0; i < int(top10Word.size()); i++)
	{
		if (i == 0)
		{
			wf << "<" << top10Word[i]->first << ">: " << -top10Word[i]->second;
		}
		else
		{
			wf << endl << "<" << top10Word[i]->first << ">: " << -top10Word[i]->second;
		}
	}
	wf.close();
	//cout << "Output Completed";
}
//获取文件名
string FileIO::getFileName(int argc, char *argv[])
{
	if (argc == 2)
	{
		return string(argv[1]);
	}
	else
	{
		cout << "Wrong Parameter! trying open default file:input.txt" << endl;
		return "input.txt";
	}
}