#include"CountCharacters.h"
#include"CountLines.h"
#include"CountWords.h"
#include"SortWords.h"
#include"PrintResult.h"
#include<map>
using namespace std;

int main(int argc, char* argv[])
{
	/*Check whether the name of the file has been entered.*/
	if (argv[1] == NULL)
	{
		cout << "Please input the filename." << endl;
		return -1;
	}
	/*Check if the number of input files is 1.*/
	if (argc!=2)
	{
		cout << "Please enter only one file." << endl;
		return -1;
	}

	int characters;
	int lines;
	int words;
	pair<string, int> top[10];
	map<string, int> MapWord;
	characters = CountCharacters(argv[1]);
	lines = CountLines(argv[1]);
	words = CountWords(argv[1],MapWord);
	SortWords(top,MapWord,words);
	PrintResult(characters, lines, words, top);
	return 0;
}