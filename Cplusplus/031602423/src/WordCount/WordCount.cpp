#include<iostream>
#include<string>
#include <fstream>
using namespace std;
int main(int argc,char* argv[])
{
	char* a = NULL;
	a = argv[1];
	ifstream infile;
	infile.open(a);   //将文件流对象与文件连接起来 
	string s;
	int count = 0;
	/*
	while (getline(infile, s))
	{
		cout << s << endl;
		int i = 0;
		while (1) {
			if (s[i] != '\0') {
				i++;
				count++;
			}
			else {
				break;
			}
		}
		//cout << s[i];
		if (s[i]=='\n') {
			cout << "ok" << endl;
			count++;
		}
	}
	*/
	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
		count++;
	}
	infile.close();
	count--;
	cout << count;
	
	return 0;
}