#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef pair<string, int> PAIR;
struct cmp
{
	bool operator()(const PAIR& lhs, const PAIR& rhs)
	{
		return lhs.second < rhs.second;
	}
};
struct comp
{
	bool operator()(const PAIR& lhs, const PAIR& rhs)
	{
		return lhs.first > rhs.first;
	}
};
int main()
{

	int num = 0, wordcount = 0, linecount = 0;
	unsigned int i, j;
	FILE *fp;
	char ch;
	string word;
	char filename[50];
	map<string, int>m;
	map<string, int>::iterator it;
	gets_s(filename);
	errno_t err;
	err = fopen_s(&fp, filename, "r");
	/*if ((err = fopen_s(&fp, "1.txt", "r")) == NULL)
	{

		printf("不存在 %s 文件\n",filename);
		return 0;
	}*/
	while (!feof(fp))fgetc(fp) && num++;

	printf("characters:%d \n", num - 1);

	rewind(fp);
	while ((ch = fgetc(fp)) != EOF)
	{
		if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
			word = word + ch;

		else
		{
			if (word.length() >= 4)
			{
				for (i = 0; i < 4; i++)
					if (!(((word[i] >= 65) && (word[i] <= 90)) || ((word[i] >= 97) && (word[i] <= 122))))
						break;//判断前四个为字母 
				if (i >= 4)
				{

					for (j = 0; j < word.length(); j++)
						if (word[j] >= 65 && word[j] <= 90)
							word[j] = word[j] + 32;

					wordcount++;

					it = m.find(word);
					if (it == m.end())
						m.insert(pair<string, int>(word, 1));

					else
						it->second++;

				}

			}
			word.erase();
			if (ch == '\n')
				linecount++;
		}

	}
	linecount++;
	printf("words:%d \n", wordcount);
	printf("lines:%d \n", linecount);

	vector<PAIR>vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), comp());
	sort(vec.begin(), vec.end(), cmp());

	
	j = 0;
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		cout << "<" << vec[i].first << ">:" << vec[i].second << endl;
		j++;
		if (j == 10)
			break;
	}
	string res;
	char res_c[1024];
	char charactersnum_s[10], wordsnum_s[10], linesnum_s[10], numrep0_s[10], numrep1_s[10], numrep2_s[10], numrep3_s[10], numrep4_s[10], numrep5_s[10], numrep6_s[10], numrep7_s[10], numrep8_s[10], numrep9_s[10];
	_itoa_s(num - 1, charactersnum_s, 10);
	_itoa_s(wordcount, wordsnum_s, 10);
	_itoa_s(linecount, linesnum_s, 10);
	_itoa_s(vec[vec.size() - 1].second, numrep0_s, 10);
	_itoa_s(vec[vec.size() - 2].second, numrep1_s, 10);
	_itoa_s(vec[vec.size() - 3].second, numrep2_s, 10);
	_itoa_s(vec[vec.size() - 4].second, numrep3_s, 10);
	_itoa_s(vec[vec.size() - 5].second, numrep4_s, 10);
	_itoa_s(vec[vec.size() - 6].second, numrep5_s, 10);
	_itoa_s(vec[vec.size() - 7].second, numrep6_s, 10);
	_itoa_s(vec[vec.size() - 8].second, numrep7_s, 10);
	_itoa_s(vec[vec.size() - 9].second, numrep8_s, 10);
	_itoa_s(vec[vec.size() - 10].second, numrep9_s, 10);

	res = res + "characters ： " + charactersnum_s + "\r\n";
	res = res + "words ： " + wordsnum_s + "\r\n";
	res = res + "lines ： " + linesnum_s + "\r\n";
	res = res + "<" + vec[vec.size() - 1].first + ">" + " ：" + numrep0_s + "\r\n";
	res = res + "<" + vec[vec.size() - 2].first + ">" + " ：" + numrep1_s + "\r\n";
	res = res + "<" + vec[vec.size() - 3].first + ">" + " ：" + numrep2_s + "\r\n";
	res = res + "<" + vec[vec.size() - 4].first + ">" + " ：" + numrep3_s + "\r\n";
	res = res + "<" + vec[vec.size() - 5].first + ">" + " ：" + numrep4_s + "\r\n";
	res = res + "<" + vec[vec.size() - 6].first + ">" + " ：" + numrep5_s + "\r\n";
	res = res + "<" + vec[vec.size() - 7].first + ">" + " ：" + numrep6_s + "\r\n";
	res = res + "<" + vec[vec.size() - 8].first + ">" + " ：" + numrep7_s + "\r\n";
	res = res + "<" + vec[vec.size() - 9].first + ">" + " ：" + numrep8_s + "\r\n";
	res = res + "<" + vec[vec.size() - 10].first + ">" + " ：" + numrep9_s + "\r\n";

	strcpy_s(res_c, res.c_str());

		FILE *fp2;
		errno_t err2;
		err2 = fopen_s(&fp2, "result.txt", "w");
		fwrite(res_c, res.length(), 1, fp2);


	return 0;

}