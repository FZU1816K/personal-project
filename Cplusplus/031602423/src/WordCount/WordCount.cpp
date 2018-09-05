#include<iostream>
#include<string>
#include <fstream>
using namespace std;
int main(int argc,char* argv[])
{
	char* a = NULL;
	a = argv[1];
	//cout << a;
	ifstream infile;
	infile.open(a);   //将文件流对象与文件连接起来 
	//assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	string s;
	while (getline(infile, s))
	{
		cout << s << endl;
	}
	infile.close();
	
	return 0;
}