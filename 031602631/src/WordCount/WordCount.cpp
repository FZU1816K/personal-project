/**************这是主调函数：WordCount******************/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Ccharacter.h" //计算字符个数的类Character
#include"Cwords.h" //计算单词个数的类Word （数据预处理）
#include"Clines.h" //计算行数的类Line
#include"Swords.h" //统计最多的10个单词及其词频的类Wsort （只需要调用Cword再进行排序就可以了吧）

/////////////////////////////////////////////////////////
int main(int argc, char * argv[])  //采用windows IDE时使用
////////////////////////////////////////////////////////
//int main()                             //单元测试时使用
////////////////////////////////////////////////////////
{
	using namespace std;

	/********************************************************
	//   测试时使用   //
	string f = "test.txt";
	for (int i = 0; i < 10000; i++) {
	/*********************************************************/

	/******************************************************/
	//   采用windows IDE时使用  //
	if (argc == 1)   //quit if no arguments
	{
		cerr << "Usage:" << argv[0] << "filename[s]\n";
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
	{
		cerr << "Input too many filenames.\n";
		exit(EXIT_FAILURE);
	}

	for (int file = 1; file < argc; file++)  //对于多个文件我采用接受的态度
	{
		string f = argv[file];
	/*********************************************************/

		Character cc(f);
		Word cw(f);
		Line cl(f);
		Wsort sw(f);
		////////////////////////////////////////////////
		cc.count(); //无参调用
		cc.show();  //无参调用
		cc.fwrite();//无参调用
		////////////////////////////////////////////////
		cw.count();
		cw.show();
		cw.fwrite();
		////////////////////////////////////////////////
		cl.count();
		cl.show();
		cl.fwrite();
		////////////////////////////////////////////////
		sw.CS();
		sw.show();
		sw.fwrite();
	}
	return 0;
}