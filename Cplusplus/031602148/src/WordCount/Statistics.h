#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

class Statistics
{
public:
	vector<int>a;//������
	map<string, int> word;//��¼���ʼ���Ƶ
	void set(ifstream& in);//����ͳ��
	void display(ofstream& out);//���ͳ�ƽ��
	int characters(ifstream& in);//ͳ���ַ���
	int	words(ifstream& in);//ͳ�Ƶ�����
	int lines(ifstream& in);//ͳ������
private:
	int cnum;//�ַ���
	int wnum;//������
	int lnum;//����
};
