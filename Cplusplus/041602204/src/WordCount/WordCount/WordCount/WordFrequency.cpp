 

#include"WordFrequency.h"
#include"Sort.h"



void WordFrequency(string filename)
{
	ofstream fout;
	const char *t;
	int flag = 0;
	int cnt = 0;
	string temp;
	unordered_map<string, int> newmap;   //使用unordered_map更为高效，其底层为hash表，而map是红黑树，效率而言自然是前者高啦~
	ifstream File(filename.c_str());      //字符读取文件

	while (File >> temp)
	{
		flag = 0;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);  //首先，将文件内容转为小写，从而满足题目要求。也方便了输出。							
		t = temp.c_str();
		if (temp.length() >= 4)
		{
			for (int i = 0; i < 4; i++)
			{
				if (t[i] >= 97 && t[i] <= 122)
					flag = flag + 1;

			}
			if (flag == 4)                      //即是满足成为单词的条件！sign=4，即表示有前四个字符为字母。
			{
				if (newmap[temp] == 0)
				{
					cnt++;
				}
				newmap[temp]++;                //通过Key值（此处为string）来查阅“hash“表，将其value（即累计字母数目）+1；
			}
		}
	}
	                                       //cout << "words:" << mm << endl;
	vector<pair<string, int> > newvector;

	Sort(newmap, newvector);                                  //进行排序。（关键）
       //输出文件result.txt                                                 //	cout << "Top10:" << endl;
	fout.open("result.txt", std::ios::out | std::ios::app);
	for (int i = 0; i < newvector.size() && i < 10; i++)        //输出词频Top10的单词，同时考虑了没有10个单词的情况。
	                                                     
	     fout <<"<"<< newvector[i].first <<">"<< ": " << newvector[i].second << endl;  //cout << tVector[i].first << ": " << tVector[i].second << endl; 
	
	fout.close();
}
