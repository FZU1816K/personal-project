
/**
* Function:  PrintResult
* Description:  Print the Result
* Parameter:
  characters:the number of characters
  lines:the number of lines
  words:the number of words
  vec:the vector
*/
#include"PrintResult.h"
void PrintResult(int characters, int lines, int words, vector<Word>& vec)
{
	ofstream outfile("result.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	outfile << "characters: " << characters << endl << "words: " << words << endl << "lines: " << lines;
	for (unsigned i = 0; i < 10 && i < vec.size(); i++)
	{
		outfile << endl << "<" << vec[i].s << ">: " << vec[i].frequency;
	}
	outfile.close();
	cout << "The result has been exported to result.txt!";
	return;
}