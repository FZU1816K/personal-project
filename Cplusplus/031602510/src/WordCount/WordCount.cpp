#include "stdafx.h"

using namespace std;

unordered_map<string, int> strMap;  //����Ľ��

bool mysort(pair < int, string > a, pair < int, string > b)
{
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}

//����string�е��ʵļ�ֵ��
void GetMap(stringstream &ss)
{
	//���ζ��뵥��
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

void LetterCount() //�ַ�ͳ�ƺ���
{
	string strFile, tmp;
	int i = 0;
	ifstream file("input.txt");      //��ȡ��ǰ�ļ�����input.txt�ļ�
	while (getline(file, tmp))//ֱ���ļ���β���������ж����ı�
	{
		strFile.append(tmp); //ÿ�ζ���һ�и��ӵ�strFile��β
		strFile.append(" ");//��β����ո�
		tmp.clear();            //�ǵ������������һ�ζ��������ı�����������ȫ���Ƕ�����
	}

	for (unsigned int i = 0; i < strFile.length(); i++)
	{
		if (ispunct(strFile[i]))
			strFile[i] = ' '; //����λ�滻��Ϊ�ո�
	}
	stringstream ss(strFile);
	
	GetMap(ss);
	//��ӡ���
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
void CharCount() //�ַ�ͳ�ƺ���
{
	FILE *fp;
	errno_t err = fopen_s(&fp, "input.txt", "r");
	int c = 0;
	char ch;
	if (err!= NULL)
	{
		printf("file read failure.");//�ļ���ȡ������ʾ
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

void WordCount() //����ͳ�ƺ���
{
	FILE *fp;
	int w = 0;
	errno_t err = fopen_s(&fp, "input.txt", "r");
	char ch;
	if (err != NULL)
	{
		printf("file read failure.");//�ļ���ȡʧ����ʾ
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
	printf("words��%d\n", w);
	fclose(fp);

}

void LineCount() //����ͳ�ƺ���
{
	FILE *fp;
	int l = 1,e=1;
	errno_t err = fopen_s(&fp, "input.txt", "r");
	char ch;
	if (err != NULL)
	{
		printf("file read failure.");//�ļ���ȡʧ����ʾ
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
	printf("lines��%d\n", l-e);
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