#include"Word.h"
#include"CountCharacters.h"
#include"CountLines.h"
#include"CountWords.h"
#include"SortWords.h"
#include"PrintResult.h"
using namespace std;
int main(int argc, char* argv[])
{
	int characters;
	int lines;
	int words;
	vector<Word> vec;
	characters = CountCharacters(argv[1]);
	lines = CountLines(argv[1]);
	words = CountWords(argv[1],vec);
	SortWords(vec);
	PrintResult(characters, lines, words,vec);
	return 0;
}
