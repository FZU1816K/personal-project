#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cctype>
#include<regex>
#include<io.h>
using namespace std;
/*宏定义*/
#define		WORD_LIMIT 4
#define     HASH_CAPACITY 456976
#define     DIGIT_FIRST 17576
#define     DIGIT_SECOND 676
#define     DIGIT_THIRD 26
#define     MOST_FREQUENT_NUM 10

/*全局变量以及结构体定义*/
typedef struct Word_Count
{
	string word;
	string trimmed;//word without digital suffix and capital character
	intptr_t number;
	struct Word_Count *next;
}MyWC;

MyWC *(ptrOfWord[HASH_CAPACITY]);
int numCharCount = 0;
int numWordCount = 0;
int numLineCount = 0;

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

/*统计行数*/
int LineCount(char* argv[])
{
	int num = 0;
	ifstream file1;
	file1.open(argv[1]);
	string str;
	while (!file1.eof())
	{
		getline(file1, str);
		num++;
	}
	file1.close();
	return num;
}

/*统计单词个数*/
MyWC *WordCount(string getWord)
{
	size_t offset = 0;
	string trimmedWord;
	MyWC *ptrTemp = NULL;
	offset = (tolower(getWord[0]) - 97)*DIGIT_FIRST;
	offset += (tolower(getWord[1]) - 97)*DIGIT_SECOND;
	offset += (tolower(getWord[2]) - 97)*DIGIT_THIRD;
	offset += tolower(getWord[3] - 97);

	numWordCount++;
	
	for (size_t i = getWord.size() - 1; i >= 0; i--)
	{
		if (isalpha(getWord[i]))
		{
			trimmedWord = "";
			for (size_t j = 0; j <= i; j++)
			{
				trimmedWord += tolower(getWord[j]);
			}

			break;
		}
	}
	if (ptrOfWord[offset] == NULL)
	{
		ptrOfWord[offset] = new MyWC;
		ptrOfWord[offset]->word = getWord;
		ptrOfWord[offset]->trimmed = trimmedWord;
		ptrOfWord[offset]->number = 1;
		ptrOfWord[offset]->next = NULL;
		ptrTemp = ptrOfWord[offset];
	}
	else
	{
		ptrTemp = ptrOfWord[offset];
		while (1)
		{
			if (ptrTemp->trimmed == trimmedWord)
			{
				if (strcmp(ptrTemp->word.c_str(), getWord.c_str()) == 1)
					ptrTemp->word = getWord;
				ptrTemp->number ++ ;

				break;
			}
			
			if (ptrTemp->next == NULL)
			{
				ptrTemp->next = new MyWC;
				ptrTemp = ptrTemp->next;
				ptrTemp->word = getWord;
				ptrTemp->trimmed = trimmedWord;
				ptrTemp->number = 1;
				ptrTemp->next = NULL;

				break;
			}
			else
			{
				ptrTemp = ptrTemp->next;
			}
		}
	}

	return ptrTemp;
 }
int main(int argc, char* argv[])
{
	ifstream file2;
	string s;
	file2.open(argv[1]);
	while (!file2.eof())
	{
		file2 >> s;
	}

	numCharCount = CharCount(argv);
	numLineCount = LineCount(argv);
	
	printf("the char num is %d", numCharCount);
	printf("the line num is %d", numLineCount);

	return 0;
}