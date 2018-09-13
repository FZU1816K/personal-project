#include "stdafx.h"

using namespace std;

unordered_map<string, int> strMap;  //保存的结果

bool mysort(pair < int, string > a, pair < int, string > b)
{
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}

//生成string中单词的键值对
void GetMap(stringstream &ss)
{
	//依次读入单词
	string strTmp;
	while (ss >> strTmp)
	{
		unordered_map<string, int>::iterator it = strMap.find(strTmp);
		if (it == strMap.end())
		{
			strMap.insert(unordered_map<string, int>::value_type(strTmp, 1));
		}
		else
			strMap[strTmp]++;
	}
}

void LetterCount() //字符统计函数
{
	string strFile, tmp;
	int i = 0;
	ifstream file("input.txt");      //读取当前文件夹下input.txt文件
	while (getline(file, tmp))//直到文件结尾，依次逐行读入文本
	{
		strFile.append(tmp); //每次读入一行附加到strFile结尾
		strFile.append(" ");//行尾补充空格
		tmp.clear();            //记得清除，否则上一次读入比这次文本长，不会完全覆盖而出错
	}

	for (unsigned int i = 0; i < strFile.length(); i++)
	{
		if (ispunct(strFile[i]))
			strFile[i] = ' '; //符号位替换成为空格
	}
	stringstream ss(strFile);
	
	GetMap(ss);
	//打印结果
	vector < pair < int, string > > v;
	for (unordered_map<string, int>::iterator it = strMap.begin(); it != strMap.end(); ++it)
		v.push_back(make_pair(it->second, it->first));
		sort(v.begin(), v.end(), mysort);
	for (unsigned int k = 0; k < v.size(); ++k)
	{
		string a = v[k].second.c_str();
		if (
			((a[0] >= 'a'&&a[0] <= 'z') || (a[0] >= 'A'&&a[0] <= 'Z')) &&
			((a[1] >= 'a'&&a[1] <= 'z') || (a[1] >= 'A'&&a[1] <= 'Z')) &&
			((a[2] >= 'a'&&a[2] <= 'z') || (a[2] >= 'A'&&a[2] <= 'Z')) &&
			((a[3] >= 'a'&&a[3] <= 'z') || (a[3] >= 'A'&&a[3] <= 'Z')) &&
			((a[4] >= 'a'&&a[4] <= 'z') || (a[4] >= 'A'&&a[4] <= 'Z') || (a[4] >= '0') && (a[4] <= '9')))
		{
			cout << '<' << a<< '>' << ":" << v[k].first<< endl;
			i++;
		}
			if (i > 9)
				break;
		}
	
	
}
void CharCount() //字符统计函数
{
	FILE *fp;
	errno_t err = fopen_s(&fp, "input.txt", "r");
	int c = 0;
	char ch;
	if (err!= NULL)
	{
		printf("file read failure.");//文件读取错误提示
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		c++;
		ch = fgetc(fp);
	}
	printf("characters: %d\n", c);
	fclose(fp);
}

void WordCount() //单词统计函数
{
	FILE *fp;
	int w = 0;
	errno_t err = fopen_s(&fp, "input.txt", "r");
	char ch;
	if (err != NULL)
	{
		printf("file read failure.");//文件读取失败提示
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{	
		int first_count = 0,last_count=0;
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		{
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
			{
				first_count++;
				ch = fgetc(fp);
			}
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')||(ch>='0'&&ch<='9'))
			{
				last_count++;
				ch = fgetc(fp);
			}
			if ((first_count >= 5) || ((first_count >= 4) && (last_count >= 1)))
			{
				w++;
			}
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	printf("words：%d\n", w);
	fclose(fp);

}

void LineCount() //行数统计函数
{
	FILE *fp;
	int l = 1,e=1;
	errno_t err = fopen_s(&fp, "input.txt", "r");
	char ch;
	if (err != NULL)
	{
		printf("file read failure.");//文件读取失败提示
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n')
		{
			l++;
			ch = fgetc(fp);
			while (ch == ' ')
			{
				ch = fgetc(fp);
			}
			while(ch == '\n')
			{
				e++;
				l++;
				ch = fgetc(fp);
			}
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	printf("lines：%d\n", l-e);
	fclose(fp);
}



int main(int argc, char *argv[])
{
	for (int i = 0; i<argc; i++)
		cout << argv[i] << endl;
	
	
	
		CharCount();
		WordCount();
		LineCount();
		LetterCount();
	//if ((strcmp(argv[1], "-a") == 0) && (strcmp(argv[2], "input.txt") == 0))
	//{
	//	Muiltiple();
	//}
		system("pause");
	return 0;
}