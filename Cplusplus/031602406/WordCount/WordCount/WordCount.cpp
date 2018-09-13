#include <iostream>
#include <fstream>
using namespace std;

using namespace std;
/*逐个字符读入文件内容*/
int CharCount(char* argv[])
{
	ifstream file1;
	file1.open(argv[1]);
	char c;
	int num = 0;
	while (!file1.eof())
	{
		file1 >> c;
		if (c >= 0 && c <= 127)
			num++;
	}
	file1.close();
	return num;

}

int main(int argc, char* argv[])
{

	int numCharCount;
	numCharCount = CharCount(argv);
	printf("the char num is %d", numCharCount);

	return 0;
}