#include"CountWords.h"
#include"Sort.h"


int CountWords(string filename)
{
	const char *k;
	int i, sign = 0, mm = 0;
	ifstream file(filename.c_str());      //字符读取文件 
	string  temp;
	unordered_map<string, int> ttmap;   //使用unordered_map更为高效，其底层为hash表，而map是红黑树，效率而言自然是前者高啦~

	while (file >> temp)
	{
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);  //首先，将文件内容转为小写，从而满足题目要求。也方便了输出。							
		k = temp.c_str();
		sign = 0;
		if (temp.length() >= 4)
		{
			for (i = 0; i < 4; i++)
			{
				if (k[i] <= 'z'&&k[i] >= 'a')
					sign += 1;

			}
			if (sign == 4)                      //即是满足成为单词的条件！sign=4，即表示有前四个字符为字母。
			{
				if (ttmap[temp] == 0)
					mm++;
				ttmap[temp]++;                //通过Key值（此处为string）来查阅“hash“表，将其value（即累计字母数目）+1；
			}
		}
	}
	return mm;
}