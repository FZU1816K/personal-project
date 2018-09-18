#include <algorithm>
#include"CharacterCount.h"
#include"WordFrequency.h"
#include"WordCount.h"
#include"LineCount.h"
using namespace std;


int main(int argc, char *argv[])
{
	if (argv[1] == NULL)
	{
		cout << "请输入文件名：" << endl;
		return -1;
	}
	Character_Count(argv[1]);//字符统计 

	Word_Count(argv[1]);//单词统计 

	Line_Count(argv[1]);//行数统计

	Frequency_Count(argv[1]);//词频统计 

	return 0;
}