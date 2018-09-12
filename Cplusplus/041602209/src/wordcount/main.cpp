#include <algorithm>
#include"CharacterCount.h"
#include"WordFrequency.h"
#include"WordCount.h"
#include"LineCount.h"
using namespace std;


int main()
{
	string filename;
	cin >> filename;
	cin.get();

	Character_Count(filename);//字符统计 

	Word_Count(filename);//单词统计 

	Line_Count(filename);//行数统计

	Frequency_Count(filename);//词频统计 

	system("pause");

	return 0;
}