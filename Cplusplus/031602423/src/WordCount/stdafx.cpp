// stdafx.cpp : source file that includes just the standard includes
// wordcount.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
//�ָ����жϲ��и��ַ���
vector<string> splitt(const string &s) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//�ҵ��ַ������׸������ڷָ�������ĸ��
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			if (isalnum(s[i]) == 0) {
				++i;
				flag = 0;
				break;
			}
		}

		//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			if (isalnum(s[j]) == 0) {//isalnum()�ж���������Ƿ�Ϊ��ĸ��������
				flag = 1;
				break;
			}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}
//�Ƚ�
int cmp(const pair<string, int>& x, const pair<string, int>& y)
{
	if (x.second != y.second)
		return x.second > y.second;
	else {
		return x.first < y.first;//�ֵ���ǰ
	}
}
//�ַ���תСд
string mytolower(string s) {
	int len = s.size();
	//cout << len<<endl;
	for (int i = 0; i<len; i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			s[i] = tolower(s[i]);
			//s[i]+=32;//+32ת��ΪСд
			//s[i]=s[i]-'A'+'a';
		}
	}
	return s;
}
//�ж��ַ����Ƿ����Ҫ��
int isstring(string c) {
	if (isdigit(c[0]) != NULL || isdigit(c[1]) != NULL || isdigit(c[2]) != NULL || isdigit(c[3]) != NULL)
		return 0;
	else
		return 1;
}

//ͳ���ַ���
int character(char* path) {
	int count = 0;
	char c;
	int i = 0;
	ifstream infile;
	infile.open(path);   //���ļ����������ļ��������� 
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		count++;
		i++;
	}
	infile.close();
	count--;
	return count;
}
//ͳ�Ƶ�����
int word(char* path) {
	ifstream infile;
	infile.open(path);   //���ļ����������ļ��������� 
	char c;
	int i = 0;
	string ff = ".";
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		if (c == '\n') {
			c = ' ';
		}
		ff += c;
		i++;
	}
	ff[i] = '\0';
	infile.close();
	ff = mytolower(ff);
	int count = 0;
	map <string, int> m1;
	map <string, int>::iterator m1_Iter;
	vector<string> split = splitt(ff);
	for (vector<string>::size_type i = 0; i != split.size(); ++i) {
		string key = split[i];
		//cout << "before:"<<key << endl;
		if (key.size() >= 4 && isstring(key) == 1) {
			if (m1.count(key) == 0)
			{
				//cout << "ok:" << key << endl;
				count++;
				m1.insert(pair <string, int>(key, 1));
			}
			else
			{
				count++;
				m1[key]++;
			}
		}
	}
	return count;
}
//ͳ������
int line(char* path) {
	int lines = 0;
	int count = 0;
	string ff = ".";
	char c;
	int i = 0;
	int flag = 0;
	ifstream infile;
	infile.open(path);   //���ļ����������ļ��������� 
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		if (c!=' '&&c!='\0'&&c!='\n')
			flag = 1;
		if (c == '\n') {
			if (flag==1) {
				lines++;
			}
			flag = 0;
			c = ' ';
		}
		ff += c;
		count++;
		i++;
	}
	ff[i] = '\0';
	infile.close();
	count--;
	if (count != 0 && flag !=0) {
		lines++;
	}
	return lines;
}
//ͳ�ƴ�Ƶ�����
vector<pair<string, int>> WordsFrequency(char* path) {
	ifstream infile;
	infile.open(path); //���ļ����������ļ��������� 
	infile >> noskipws;
	char c;
	int i = 0;
	string ff = ".";
	while (!infile.eof())
	{
		infile >> c;
		if (c == '\n') {
			c = ' ';
		}
		ff += c;
		i++;
	}
	ff[i] = '\0';
	infile.close();
	ff = mytolower(ff);
	vector<string> split = splitt(ff);
	map <string, int> m1;
	map <string, int>::iterator m1_Iter;
	vector<pair<string, int>> tVector;
	for (vector<string>::size_type i = 0; i != split.size(); ++i) {
		//cout << split[i] << endl;
		string key = split[i];
		if (key.size() >= 4 && isstring(key) == 1) {
			//cout << "�����������ַ����ǣ�" << key << endl;
			if (m1.count(key) == 0)
			{
				m1.insert(pair <string, int>(key, 1));
			}
			else
			{
				m1[key]++;
			}
		}
	}
	//map <string, int>::iterator m1_temp;
	for (map<string, int>::iterator curr = m1.begin(); curr != m1.end(); curr++)
		tVector.push_back(make_pair(curr->first, curr->second));
	sort(tVector.begin(), tVector.end(), cmp);
	return tVector;
}