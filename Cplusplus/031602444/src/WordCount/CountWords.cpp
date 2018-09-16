<<<<<<< HEAD
#include"CountWords.h"
using namespace std;


int CountWords(char* filemm)//统计词数
{
	string s;
	vector<int> ans;//存分隔符位置
	int words = 0;

	ifstream f;

	f.open(filemm, ios::in);


	while (f >> s) //一次读取一个字符串，读取字符串不包括换行和空格和制表符
	{

		ans.clear();
		int ssize = s.size();
		for (int i = 0; i < ssize; i++)
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
				words++;
			}
			continue;
		}

		//否则就有一个以上的分隔符
		//先判断第一个，因为第一个没有分隔符做开头标记
		if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
		{
			words++;
		}

		for (int i = 0; i < ans.size(); i++)
		{
			//满足分隔符后四个字符是字母
			if ((s[ans[i] + 1] >= 97 && s[ans[i] + 1] <= 122) && (s[ans[i] + 2] >= 97 && s[ans[i] + 2] <= 122) &&
				(s[ans[i] + 3] >= 97 && s[ans[i] + 3] <= 122) && (s[ans[i] + 4] >= 97 && s[ans[i] + 4] <= 122))
			{
				words++;
			}
		}
	}

	f.close();

	return words;

=======
#include"CountWords.h"
using namespace std;


int CountWords(char* filemm)//统计词数
{
	string s;
	vector<int> ans;//存分隔符位置
	int words = 0;

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
				words++;
			}
			continue;
		}

		//否则就有一个以上的分隔符
		//先判断第一个，因为第一个没有分隔符做开头标记
		if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
		{
			string temp(s.substr(0, ans[0]));//满足前四个字符是字母，截取
			words++;
		}

		for (int i = 0; i < ans.size(); i++)
		{
			//满足分隔符后四个字符是字母
			if ((s[ans[i] + 1] >= 97 && s[ans[i] + 1] <= 122) && (s[ans[i] + 2] >= 97 && s[ans[i] + 2] <= 122) &&
				(s[ans[i] + 3] >= 97 && s[ans[i] + 3] <= 122) && (s[ans[i] + 4] >= 97 && s[ans[i] + 4] <= 122))
			{
				string temp(s.substr(ans[i] + 1, ans[i + 1] - ans[i] - 1));
				words++;
			}
		}
	}

	f.close();

	return words;

>>>>>>> dc50c84c71cf40269e6de56f0ab724fcbbb665bf
}