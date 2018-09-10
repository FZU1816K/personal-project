#include "FileIO.h"

string FileIO::readChar(int argc, char *argv[])
{
	string filename = FileIO::getFileName(argc, argv);
	ifstream rf(filename);
	string charBuf;
	char c;
	while ((c = rf.get()) != EOF)
	{
		charBuf += c;
	}
	return charBuf;
}
vector<string> FileIO::readLines(int argc, char *argv[])
{
	string filename = FileIO::getFileName(argc, argv);
	ifstream rf(filename);
	string tempStr;
	vector<string> lineBuf;
	while (getline(rf, tempStr)) 
	{
		lineBuf.push_back(tempStr);
	}
	return lineBuf;
}
void FileIO::outputToFile(int characterCount, int wordCount,int lineCount, vector<pair<string, int> > &top10Word)
{
	ofstream wf("result.txt", ios::out);
	wf << "characters:" << characterCount << endl
		<< "words: " << wordCount << endl
		<< "lines:" << lineCount << endl;
	for (int i = 0; i < int(top10Word.size()); i++)
	{
		if (i == 0)
		{
			wf << "<" << top10Word[i].first << ">: " << top10Word[i].second;
		}
		else
		{
			wf << endl << "<" << top10Word[i].first << ">: " << top10Word[i].second;
		}
	}
}

string FileIO::getFileName(int argc, char *argv[])
{
	if (argc == 2)
	{
		return string(argv[1]);
	}
	else
	{
		cout << "Wrong Parameter! trying open input.txt" << endl;
		return "input.txt";
	}
}