#include"CountAndSort.h"
using namespace std;


void CountAndSort(char* filemm, vector<pair<string, int>>& x)//ͳ�ƴ�����Ƶ
{
	map<string, int> mapp;
	string s;
	vector<int> ans;//��ָ���λ��

	ifstream f;

	f.open(filemm, ios::in);

	while (f >> s) //һ�ζ�ȡһ���ַ�������ȡ�ַ������������кͿո���Ʊ��
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

		if (ans.size() == 0)//����ָ����Ŀ����0������ֻ��һ���ַ���
		{
			//����Ӹ÷������ĸ��ַ�������ĸ
			if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
			{
				mapp[s]++;
			}
			continue;
		}

		//�������һ�����ϵķָ���
		//���жϵ�һ������Ϊ��һ��û�зָ�������ͷ���
		if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
		{
			string temp(s.substr(0, ans[0]));//����ǰ�ĸ��ַ�����ĸ����ȡ
			mapp[temp]++;
		}

		for (int i = 0; i < ans.size(); i++)
		{
			//����ָ������ĸ��ַ�����ĸ
			if ((s[ans[i] + 1] >= 97 && s[ans[i] + 1] <= 122) && (s[ans[i] + 2] >= 97 && s[ans[i] + 2] <= 122) &&
				(s[ans[i] + 3] >= 97 && s[ans[i] + 3] <= 122) && (s[ans[i] + 4] >= 97 && s[ans[i] + 4] <= 122))
			{
				string temp(s.substr(ans[i] + 1, ans[i + 1] - ans[i] - 1));
				mapp[temp]++;
			}
		}
	}


	f.close();

	/*vector<pair<string, int>> w(mapp.begin(), mapp.end());//��Ƶ����
	x=w;
	sort(x.begin(), x.end(), SortByValue());*/


	vector<pair<string, int>> v(mapp.begin(), mapp.end());//��Ƶ����


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
				max = vec->second;//���µ�ǰ���������
				maxword = vec->first;
			}
			else if (vec->second == max)//�ֵ���
			{
				if (vec->first < maxword)
				{
					max = vec->second;//���µ�ǰ���������
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
