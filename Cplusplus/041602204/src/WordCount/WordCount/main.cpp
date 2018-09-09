#include<iostream>
#include<fstream>
#include<string>
#include"CountChar.h"
#include"CountLines.h"
using namespace std;
int main(int argc,char **argv)
{
	int temp=initialization(argc,argv);
	if(temp==-1) {
		cout<<"Sorry, something errors happened!"<<endl;
		return 0;
	}
	
}
