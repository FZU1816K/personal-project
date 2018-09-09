#include"core.h"

#pragma warning(disable:4996)
using namespace std;

extern int characters;
extern int lines;
extern int words;

FILE * stream;

int main(int argc, char* argv[])
//int main()
{
	//freopen_s(&stream, "result.txt", "w", stderr);
	freopen("result.txt", "w", stdout);
	ifstream f;
	f.open(argv[1], ios::in);
	if (!f)
	{
		cout << "文件不存在或路径错误或不是txt形式!" << endl;
		return 0;
	}
	CountCharacters(f);
	f.close();
	f.open(argv[1], ios::in);
	map<string, int> m;
	CountWord(f, m);
	printf("characters: %d\n", characters);
	printf("words: %d\n", words);
	printf("lines: %d\n", lines);
	SortWord(m);
	f.close();
	//system("pause");
	return 0;
}