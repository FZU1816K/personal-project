#include "stdafx.h"

int main(int args,char* argv[])
{
	char* a = NULL;
	vector<pair<string, int>> tVector;
	//char* a = "input.txt";
	ofstream fout("result.txt");
	a = argv[1];
	if (argv[1] == NULL)
	{
		cout << "û�������ı�·����" << endl;
		return 1;
	}
	else if (argv[2] != NULL)
	{
		cout << "����������࣡" << endl;
		return 2;
	}
	string filename = argv[1];
	ifstream input;
	input.open(filename);
	if (input.fail())
	{
		cout << "�ļ������ڣ�" << endl;
		return 3;
	}
	input.close();

	int characters,words;
	//���ͳ���ַ���
	characters = character(a);
	fout << "characters: " << characters << endl;
	//���ͳ�Ƶ�����
	words = word(a);
	fout << "words: " << words << endl;
	int lines = line(a);
	fout << "lines: " << lines << endl;
	//���ͳ��ǰʮ��Ƶ
	tVector=WordsFrequency(a);
	for (int i = 0; i<tVector.size(); i++)
	{
		if (i == 10)
			break;
		fout << "<" << tVector[i].first << ">" << ": " << tVector[i].second << endl;
	}
	fout.close();
	return 0;
}