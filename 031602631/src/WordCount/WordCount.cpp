/**************这是主调函数：WordCount******************/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Ccharacter.h" //计算字符个数的类Character
#include"Cwords.h" //计算单词个数的类Word （数据预处理）
#include"Clines.h" //计算行数的类Line
#include"Swords.h" //统计最多的10个单词及其词频的类Wsort （只需要调用Cword再进行排序就可以了吧）
/////////////////////////////////////////////////////////
//int main(int argc, char * argv[])  //采用windows IDE
////////////////////////////////////////////////////////
int main()
{
	using namespace std;


	string f = "test.txt";
	for (int i = 0; i < 10000; i++) {
		/******************************************************
		if (argc == 1) //quit if no arguments
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
			////////////////////////////////////////////////
		*********************************************************/

		Character Cc(f);
		Word cw(f);
		Line cl(f);
		Wsort sw(f);
		////////////////////////////////////////////////
		Cc.count(); //这是里面的计数函数
		Cc.show(); //显示结果
		Cc.fwrite();
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
		//	}
	}
	return 0;
}