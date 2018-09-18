#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<regex>
#include<list>
using namespace std;
typedef list<string> List;

//���ֵ��ʼ�����ָ�������
class countWord
{
public:
	string name;
	int count;
	bool operator < (countWord& w1)//����<�����
	{
		return count > w1.count;
	}
};
typedef list<countWord> Wordlist;
//�ļ��࣬ʵ�ָ�������ļ��Ĳ���
class File
{
public:
	File();
	void ShuRufile(string filename);
	void ShuChufile();
	void Wordscount(string filename);
private:
	int characters;
	int wordscount;
	int lines;
	List words;
	Wordlist words_count;
};
#pragma once
