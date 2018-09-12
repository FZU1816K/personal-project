#include "stdafx.h"
#include "Statistics.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)//�������������в����Ƿ���ȷ
	{
		cout << "�����������" << endl;
		exit(1);
	}
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1], ios::in);
	if (infile.fail())
	{
		cout << "�����ļ���ʧ�ܣ�" << endl;
		exit(1);
	}
	outfile.open("result.txt", ios::out);
	if (outfile.fail())
	{
		cout << "����ļ���ʧ�ܣ�" << endl;
		exit(1);
	}
	Statistics	s;
	s.set(infile);
	s.display(outfile);
	infile.close();
	outfile.close();
	return 0;
}