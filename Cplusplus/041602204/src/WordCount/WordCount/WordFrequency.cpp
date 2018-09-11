/*#include"WordFrequency.h"


void display_map(map<string, int> &wmap)
{
	map<string, int>::const_iterator map_it;
	for (map_it = wmap.begin(); map_it != wmap.end(); map_it++)
	{
		cout << "(\"" << map_it->first << "\"," << map_it->second << ")" << endl;
	}
}

int WordFrequency(char *filename)   //初稿，只完成了词频统计，并未完成Top10的功能
{
	using namespace std;
	const char *k;
	std::fstream file;
	int i, sign;
	string  temp;
	cin.get();
	ifstream fin(filename.c_str());
	map<string, int> wmap;

	while (fin >> temp)
	{
		k = temp.c_str();
		sign = 0;
		if (temp.length() >= 4)
		{
			for (i = 0; i < 4; i++)
			{
				if (k[i] <= '9'&&k[i] >= '0')
					sign = 1;

			}
			if (sign == 0)
				wmap[temp]++;
		}
	}
	display_map(wmap);
	fin.close();
}
*/

#include"WordFrequency.h"
#include"Sort.h"



void WordFrequency(string filename)
{
	ofstream fout;
	const char *k;
	int i, sign = 0,mm=0;
	ifstream fin(filename.c_str());      //字符读取文件 
	string  temp;
	unordered_map<string, int> wmap;   //使用unordered_map更为高效，其底层为hash表，而map是红黑树，效率而言自然是前者高啦~

	while (fin >> temp)
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
				if (wmap[temp] == 0)
					mm++;
				wmap[temp]++;                //通过Key值（此处为string）来查阅“hash“表，将其value（即累计字母数目）+1；
			}
		}
	}
	cout << "words:" << mm << endl;
	vector<pair<string, int> > tVector;

	Sort(wmap, tVector);                                  //进行排序。（关键）
       //输出文件result.txt                                                 //	cout << "Top10:" << endl;
	fout.open("result.txt");
	for (int i = 0; i < tVector.size() && i < 10; i++)        //输出词频Top10的单词，同时考虑了没有10个单词的情况。
	                                                     
	     fout << tVector[i].first << ": " << tVector[i].second << endl;  //cout << tVector[i].first << ": " << tVector[i].second << endl; 
	
	fout.close();
}
