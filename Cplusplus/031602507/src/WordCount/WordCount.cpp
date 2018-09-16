/********************************************************************************
* @File name: wc.cpp
* @Author: ChenYuXin
* @Version: 4.0
* @Date: 2018-09-11
* @Description: update FileIO.h & FileIO.cpp
********************************************************************************/


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include<map>
#include<algorithm>
#include"Count.h"	//��װ���е�ͳ����صĹ���
#include"FileIO.h"	//��װ�����ļ���д��صĹ���
using namespace std;



int main(int argc, char *argv[]) 
{
	for (int i = 0; i < 1; i++)
	{
		int lineCount = 0;			//����
		int characterCount = 0;		//�ַ���
		int wordCount = 0;			//������

		Count count;
		string charBuf;
		vector<string> linesBuf;
		FileIO::readChar(argc, argv,charBuf,linesBuf);			//����ַ���ȡ�ļ�������charBuf
		/*for (auto it = linesBuf.begin(); it != linesBuf.end(); it++)
		{
			cout << *it << endl;
		}*/
		characterCount = count.countCharNum(charBuf);			//�����ַ���
		lineCount = count.countLineNum(linesBuf);				//��������
		wordCount = count.countWordNum(linesBuf);				//���㵥����
		vector<map<string,int>::iterator> top10Word = count.countTop10Word();	//ͳ�Ƴ���Ƶ����ߵ�10�����ʣ��п��ܵ�����û��10����

		FileIO::outputToFile(characterCount, wordCount, lineCount, top10Word);	//�����������ļ�
	}

	//system("pause");
	return 0;
}