#define _CRT_SECURE_NO_WARNINGS

#include <map>     
#include <fstream>     
#include <iostream>     
#include <string> 
#include <regex>
#include "Countlines.h"

using namespace std;

int cnt[3] = { 0 };


void display_map(map<string, int> &wmap);
/**
*function��ͳ���ı���ÿ�����ʳ��ֵĴ���
*/
int main(int argc, char* argv[]) 
	{
	string str;
	char filename[256];
	//int cnt[3] = { 0 };
	//const char *mInputFileName = "1.txt";
	ifstream ifs(argv[1]);
	
	string mStrTemp;
	map<string, int> mCountMap;
	//���ж����ļ����������ҳ����ʣ�����ͳ��
	regex regWordPattern("[a-zA-Z]+");//���ʵ�����ʽ��1��\w+:�������� 2)[a-zA-Z]:ֻ����ĸ
	while (getline(ifs, mStrTemp))
	{//���ж���
		const std::sregex_token_iterator end;
		for (sregex_token_iterator wordIter(mStrTemp.begin(), mStrTemp.end(), regWordPattern); wordIter != end; wordIter++)
		{//��һ���ı�������ҳ�����
			//cout<<*wordIter<<endl;//ÿ������
			mCountMap[*wordIter]++;//���ʼ���
		}
	}


	//cout << "please input your filename:" << endl; //����Ҫͳ�Ƶ��ı��ľ���·��
	//cin.getline(filename, 256);
	fstream outfile(argv[1], ios::in);
	count(outfile, cnt);

	ofstream oufile;
	oufile.open("result.txt");
	oufile << "characters: " << cnt[0] << endl;
	oufile << "words:";
	oufile.close();
	display_map(mCountMap);
	//cout << "lines:" << cnt[2] << endl;
	
	outfile.close();
	system("pause");
	return 0;
	system("pause");
	return 0;
	return 1;
}




struct ww
{
	char word[20];
	int number;
}w[1000];
void display_map(map<string, int> &wmap)
{


	map<string, int>::const_iterator map_it;


	int i, j, num = 0;
	int t = 0;
	int tt = 0, ttt, x = 0;
	char  cc[20];

	for (map_it = wmap.begin(); map_it != wmap.end(); map_it++)
	{

		num += map_it->second;
		strcpy(w[t].word, (map_it->first).c_str());
		w[t].number = map_it->second;
		t++;

	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < strlen(w[i].word); j++)
		{
			if (w[i].word[j] >= 'A'&& w[i].word[j] <= 'Z')
			{
				w[i].word[j] += 32;
			}
		}
	}
	ttt = t - 2;
	for (j = tt; j < ttt; j++)
	{
		for (i = 0; i < ttt - j; i++)
		{
			if (w[i].number < w[i + 1].number)
			{
				x = w[i].number; w[i].number = w[i + 1].number; w[i + 1].number = x;
				strcpy(cc, w[i].word);
				strcpy(w[i].word, w[i + 1].word);
				strcpy(w[i + 1].word, cc);
			}
			
		}
	}
	int p;
	for (p = 0; p < t; p++)
	{
		if (w[p].number = w[p + 1].number)
		{
			if (strcmp(w[p].word, w[p + 1].word) > 0)
			{
				strcpy(cc, w[p].word);
				strcpy(w[p].word, w[p + 1].word);
				strcpy(w[p + 1].word, cc);
			}
			
		}
	}
	ofstream outfile;
	outfile.open("result.txt", std::ios::app);
	outfile << num << endl;
	outfile << "lines :" << cnt[2] << endl;
	for (j = tt; j < 10; j++)
	{
		outfile <<'<' << w[j].word << '>'<<":" << w[j].number << endl;
	}
	
	
	outfile.close();
}
