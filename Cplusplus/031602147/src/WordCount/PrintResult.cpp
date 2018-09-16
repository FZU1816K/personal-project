/**
* Function:  PrintResult
* Description:  Print the Result
* Parameter:
  characters:the number of characters
  lines:the number of lines
  words:the number of words
  top:the highest frequency word array
*/
#include"PrintResult.h"
void PrintResult(int characters, int lines, int words, pair<string, int> top[])
{
	ofstream outfile("result.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	outfile << "characters: " << characters << endl << "words: " << words << endl << "lines: " << lines;
	for (int i = 0; i < 10 && i<words; i++)
	{
		outfile << endl << "<" << top[i].first<< ">: " << top[i].second;
	}
	outfile.close();
	return;
}