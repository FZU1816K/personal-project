/**
* Function:  CountWords
* Description:  Count the number of words of the file
* Parameter:
  file:File that need to be counted
  MapWord:the words map
* Return:
  int:the number of words
*/
#include"CountWords.h"
#include"MatchWord.h"
int CountWords(char *file, map<string, int> &MapWord)
{
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
	int sign = 0;
	while (!feof(fp))
	{
		if ((ch = getc(fp)) != EOF)
		{
			if (0 <= ch && ch <= 255)
			{
				if (65 <= ch && ch <= 90)//A-Z
				{
					if (!sign)
					{
						cnt++;
						ch = ch + 32;
						/*capitalization of English letters into lowercase letters*/
						s = s + ch;
					}

				}
				else if (97 <= ch && ch <= 122)//a-z
				{
					if (!sign)
					{
						cnt++;
						s = s + ch;
					}
				}
				else if (48 <= ch && ch <= 57)//0-9
				{
					if (cnt >= 4)
					{
						cnt++;
						s = s + ch;
					}
					else
					{
						sign = 1;
						/*exclude words beginning with numbers.*/
					}
				}
				else
				{
					if (cnt >= 4)
					{
						MatchWord(s, MapWord);
					}
					s = "";
					cnt = 0;
					sign = 0;
				}
			}
		}
	}
	if (cnt >= 4)
	{
		MatchWord(s, MapWord);
	}
	int number = 0;
	map<string, int>::iterator iter;
	for (iter = MapWord.begin(); iter != MapWord.end(); ++iter)
	{
		number += iter->second;/*Count words*/
	}
	s = "";
	cnt = 0;
	fclose(fp);
	return number;
}