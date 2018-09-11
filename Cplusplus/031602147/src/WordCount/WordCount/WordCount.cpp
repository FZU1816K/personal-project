#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<fstream>
#include<algorithm>
#include<windows.h>

using namespace std;

struct Word {
	string s;
	int frequency;
};

vector<Word> vec;
/**
 * Function:  cmp
 * Description:  The comparison function of vector sorting method sort
 */
int cmp(Word w1, Word w2)
{
	if (w1.frequency != w2.frequency)
	{
		return w1.frequency > w2.frequency;
	}
	else
	{
		return w1.s < w2.s;
	}
}

/**
 * Function:  CountCharacters
 * Description:  Count the number of characters of the file
 * Parameter:
   file:File that need to be counted
 * Return:
   int:the number of characters
 */
int CountCharacters(char *file)
{
	int number = 0;
	char ch;
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, file, "r")) != 0)
	{
		printf("Can not open this file.\n");
		exit(0);
	}
	while (!feof(fp))
	{
		if ((ch = getc(fp)) != EOF)
		{
			if (0 <= ch && ch <= 255)number++;
		}
	}
	fclose(fp);
	return number;
}

/**
 * Function:  CountLines
 * Description:  Count the number of lines of the file
 * Parameter:
   file:File that need to be counted
 * Return:
   int:the number of lines
 */
int CountLines(char *file)
{
	int number = 0;//lines
	FILE *fp;
	char ch;
	errno_t err;
	if ((err = fopen_s(&fp, file, "r")) != 0)
	{
		printf("Can not open this file.\n");
		exit(0);
	}
	while (!feof(fp))
	{
		if ((ch = getc(fp)) != EOF)
		{
			if ((ch = getc(fp)) == '\n')
			{
				if (file[0] != '\0') number++;
			}
		}
	}
	fclose(fp);
	return number + 1;
}

/**
* Function:  MatchWord
* Description:  Judge whether the word is in the vector.
* Parameter:
  s:word that need to be judged
* Return:
  bool:the word is in the vector or not
*/
bool MatchWord(string s)
{
	bool flag = false;
	unsigned i;
	for (i = 0; i < vec.size(); i++)
	{
		if (vec[i].s == s)
		{
			flag = true; break;
		}
	}
	if (!flag)
	{
		Word w;
		w.s = s;
		w.frequency = 1;
		vec.push_back(w);
	}
	else
	{
		vec[i].frequency++;
	}
	return flag;
}

/**
* Function:  CountWords
* Description:  Count the number of words of the file
* Parameter:
  file:File that need to be counted
* Return:
  int:the number of words
*/
int CountWords(char *file)
{
	int number = 0;
	char ch;
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, file, "r")) != 0)
	{
		printf("Can not open this file.\n");
		exit(0);
	}
	string s;
	int cnt = 0;
	while (!feof(fp))
	{
		if ((ch = getc(fp)) != EOF)
		{
			if (0 <= ch && ch <= 255)
			{
				if (65 <= ch && ch <= 90)
				{
					cnt++;
					ch = ch + 32;
					s = s + ch;
				}
				else if (97 <= ch && ch <= 122)
				{
					cnt++;
					s = s + ch;
				}
				else if (48 <= ch && ch <= 57)
				{
					if (cnt >= 4)
					{
						cnt++;
						s = s + ch;
					}
				}
				else
				{
					if (cnt >= 4)
					{
						if (!MatchWord(s)) number++;
					}
					s = "";
					cnt = 0;
				}
			}
		}
	}
	if (cnt >= 4)
	{
		if (!MatchWord(s)) number++;
	}
	s = "";
	cnt = 0;
	fclose(fp);
	return number;
}

/**
* Function:  SortWords
* Description:  Sort the words
*/
void SortWords()
{
	sort(vec.begin(), vec.end(), cmp);
	return;
}

/**
* Function:  PrintResult
* Description:  Print the Result
* Parameter:
  characters:the number of characters
  lines:the number of lines
  words:the number of words
*/
void PrintResult(int characters, int lines, int words)
{
	ofstream outfile("result.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	outfile << "characters:" << characters << endl << "lines:" << lines << endl << "words:" << words;
	for (unsigned i = 0; i < 10 && i < vec.size(); i++)
	{
		outfile << endl << "<" << vec[i].s << ">:" << vec[i].frequency;
	}
	outfile.close();
	return;
}

int main(int argc, char *argv[])
{
	int characters;
	int lines;
	int words;
	char filename[30] = { 0 };
	gets_s(filename);
	characters = CountCharacters(filename);
	lines = CountLines(filename);
	words = CountWords(filename);
	SortWords();
	PrintResult(characters, lines, words);
	return 0;
}