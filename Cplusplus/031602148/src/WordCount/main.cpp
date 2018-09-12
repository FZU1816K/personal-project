#include "stdafx.h"
#include "Statistics.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)//检测输入的命令行参数是否正确
	{
		cout << "输入参数错误！" << endl;
		exit(1);
	}
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1], ios::in);
	if (infile.fail())
	{
		cout << "输入文件打开失败！" << endl;
		exit(1);
	}
	outfile.open("result.txt", ios::out);
	if (outfile.fail())
	{
		cout << "输出文件打开失败！" << endl;
		exit(1);
	}
	Statistics	s;
	s.set(infile);
	s.display(outfile);
	infile.close();
	outfile.close();
	return 0;
}