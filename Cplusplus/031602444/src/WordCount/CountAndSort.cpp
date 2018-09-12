#include"CountAndSort.h"
using namespace std;


void CountAndSort(char* filemm, vector<pair<string, int>>& x)//统计词数词频
{
	map<string, int> mapp;
	string s;
	vector<int> ans;//存分隔符位置

	ifstream f;

	f.open(filemm, ios::in);

	while (f >> s) //一次读取一个字符串，读取字符串不包括换行和空格和制表符
	{

		ans.clear();

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				s[i] += 32;
			}
			if (s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i]>122)
			{
				ans.push_back(i);
			}
		}

		if (ans.size() == 0)//如果分割符数目等于0，就是只有一个字符串
		{
			//如果从该符号起四个字符都是字母
			if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
			{
				mapp[s]++;
			}
			continue;
		}

		//否则就有一个以上的分隔符
		//先判断第一个，因为第一个没有分隔符做开头标记
		if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
		{
			string temp(s.substr(0, ans[0]));//满足前四个字符是字母，截取
			mapp[temp]++;
		}

		for (int i = 0; i < ans.size(); i++)
		{
			//满足分隔符后四个字符是字母
			if ((s[ans[i] + 1] >= 97 && s[ans[i] + 1] <= 122) && (s[ans[i] + 2] >= 97 && s[ans[i] + 2] <= 122) &&
				(s[ans[i] + 3] >= 97 && s[ans[i] + 3] <= 122) && (s[ans[i] + 4] >= 97 && s[ans[i] + 4] <= 122))
			{
				string temp(s.substr(ans[i] + 1, ans[i + 1] - ans[i] - 1));
				mapp[temp]++;
			}
		}
	}


	f.close();

	/*vector<pair<string, int>> w(mapp.begin(), mapp.end());//词频排序
	x=w;
	sort(x.begin(), x.end(), SortByValue());*/


	vector<pair<string, int>> v(mapp.begin(), mapp.end());//词频排序


	for (int i = 0; i < mapp.size(); i++)
	{
		if (i == 10) break;
		int max = 0;
		string maxword;
		int enflag = 0;
		for (vector<pair<string, int>>::iterator vec = v.begin(); vec != v.end(); vec++)
		{
			if (vec->second > max)
			{
				max = vec->second;//存下当前最大数单词
				maxword = vec->first;
			}
			else if (vec->second == max)//字典序
			{
				if (vec->first < maxword)
				{
					max = vec->second;//存下当前最大数单词
					maxword = vec->first;
				}
			}
		}

		if (max) x.push_back(make_pair(maxword, max));

		for (vector<pair<string, int>>::iterator vec = v.begin(); vec != v.end(); vec++)
		{
			if (vec->first == maxword)
			{
				vec->second = -1;
				break;
			}

		}
	}




}


int Display(vector<pair<string, int>>& x)
{
	int vecflag = 0;

	for (vector<pair<string, int>>::iterator vec = x.begin(); vec != x.end(); vec++)
	{

		printf("<%s>: %d\n", vec->first, vec->second);

		vecflag++;
		if (vecflag == 10) break;

	}

	return vecflag;
}
