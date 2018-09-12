#include <string>
#include <iostream>
#include <fstream>
#include "pch.h"
#include "File.h"
#include "CountAscii.h"
#include "CountWords.h"
#include "CountFrequence.h"
#include <fstream>
using namespace std;
unordered_map<string, int> strMap;
void File::file_output(string input_fname, string output_fname)
{
	Ascii asc;
	Word word;
	Frequence fre;
	ofstream file(output_fname);
	if (!file)
	{
		cout << "不存在这个文件或者文件未打开，请重新输入！" << endl;
		exit(0);
	}
	int count_ascii;
	int count_word = 0;
	int count_line;
	count_ascii = asc.countAscii(input_fname);
	strMap = word.count_Word(input_fname, strMap);
	count_line = asc.countLine(input_fname);
	unordered_map<string, int>::const_iterator it;
	for (it = strMap.begin(); it != strMap.end(); ++it)
	{
		//cout << it->first << "：" << it->second << endl;
		count_word++;
	}
	file << "characters:" << count_ascii << endl;
	file << "words:" << count_word << endl;
	file << "lines:" << count_line << endl << endl;
	fre.output_Frequency(output_fname, strMap);
	file.close();
}