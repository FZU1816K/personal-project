#include "stdafx.h"

int main()
{
	cout << "����Ҫд����ļ�·�����ļ�����" << endl;
	string filename;
	cin >> filename;
	File file;
	file.ShuRufile(filename);
	file.Wordscount(filename);
	//cout << "����Ҫ��ȡ���ļ�·�����ļ�����" << endl;
	//cin >> filename;
	file.ShuChufile();
	system("pause");
	return 0;
}