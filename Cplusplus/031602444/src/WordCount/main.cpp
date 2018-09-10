#include"CountCharacters.h"
#include"CountLines.h"
#include"CountWords.h"
#include"CountAndSort.h"

#pragma warning(disable:4996)
using namespace std;

extern int characters;
extern int lines;
extern int words;

//FILE * stream;

int main(int argc, char* argv[])
{
	
	//freopen_s(&stream, "result.txt", "w", stderr);
		freopen("result.txt", "w", stdout);

		if (argv[1] == NULL)
		{
			printf("请输入文件路径\n");
			return -1;
		}


		ifstream f;
		f.open(argv[1], ios::in);
		if (!f)
		{
			printf("无法打开文件\n");
			return -1;
		}
		f.close();

		int charsss = CountCharacters(argv[1]);
		int linesss = CountLines(argv[1]);
		int wordsss = CountWords(argv[1]);

		printf("characters: %d\n", charsss);
		printf("words: %d\n", wordsss);
		printf("lines: %d\n", linesss);

		vector<pair<string, int>> v;
		CountAndSort(argv[1],v);
		int num = Display(v);
		v.clear();


	
	return 0;
}